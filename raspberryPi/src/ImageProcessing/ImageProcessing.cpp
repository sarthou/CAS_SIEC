#include "ImageProcessing/ImageProcessing.hpp"
#include "Interface/ImageInterface.h"
#include <unistd.h>



positionVoiture findTags(const Mat& image, vector<vector<Point2f> >& squares ){
	positionVoiture returnValue;
	squares.clear();
	cv::Mat inputImage;

	 vector< int > markerIds;
	 vector< vector<Point2f> > markerCorners, rejectedCandidates;
	 //cv::Ptr<aruco::DetectorParameters> parameters;
	 cv::Ptr<aruco::DetectorParameters> parameters = aruco::DetectorParameters::create();
	 cv::Ptr<aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_ARUCO_ORIGINAL );
	 cv::Mat markerImage;
	 cv::aruco::drawMarker(dictionary, 23, 200, markerImage, 1);
	 cv::aruco::detectMarkers(image, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);
	 //cv::aruco::drawDetectedMarkers(inputImage, markerCorners, markerIds);

	 //cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
	 imwrite("img.jpg", markerImage);
	 //for(int i=0; i< markerIds.size(); i++){
		 cout << markerIds.size() <<endl;
		 if(markerIds.size() != 0){
			 cout << markerIds[0]<<endl;
			 cout << markerCorners[0][0]<<endl;
			 cout << markerCorners[0][1]<<endl;
			 cout << markerCorners[0][2]<<endl;
			 cout << markerCorners[0][3]<<endl;
			 squares.push_back(markerCorners[0]);


			 vector<int> coordonneesY;
			 for (size_t i=0; i<markerCorners[0].size(); i++){
				 coordonneesY.push_back(markerCorners[0][i].y);
				 //std::cout<<"Les coordonnées du point "<<i<<" sont : "<<approx[i]<<endl;
			 }

			//Calcul du côté
			float centre = (float)(markerCorners[0][0].x+markerCorners[0][1].x+markerCorners[0][2].x+markerCorners[0][3].x)/4.0;
								//float pourcentage;
			if(centre > 340.0){
					//cout << "La voiture est à droite: ";
				returnValue.side = 1;
				returnValue.percentageSide =((float)(centre - 340.0)/250.0)*100.0;
				//cout << pourcentage << " %" << endl;
			} else {
				//cout << "La voiture est à gauche: ";
				returnValue.side = 0;
				returnValue.percentageSide = ((float)(340.0-centre)/250.0)*100.0;
				//cout << pourcentage << " %" << endl;
			}

			//Calcul de la distance
			int maxH = 0;
			maxH = MAX(maxH, abs(coordonneesY[0]-coordonneesY[3]));
			maxH = MAX(maxH, abs(coordonneesY[0]-coordonneesY[1]));
			maxH = MAX(maxH, abs(coordonneesY[0]-coordonneesY[2]));
			maxH = MAX(maxH, abs(coordonneesY[1]-coordonneesY[2]));
			maxH = MAX(maxH, abs(coordonneesY[1]-coordonneesY[3]));
			//std::cout<<"La hauteur est "<<maxH;
			float maxHeight = ((float)maxH)/2.0;
			//std::cout<<"La distance est "<<
			returnValue.dist = 4203.9*pow(maxHeight, -0.987);
	 }

	 return returnValue;

}

void threadProcessing(){
  //Open the capture device

	uint32_t depth = 1000;
  VideoCapture capture;
	capture.set(CV_CAP_PROP_BUFFERSIZE, 3);
  capture.open(0);
  if ( !capture.isOpened() )  // if not success, exit program
  {
    cout << "Cannot open the web cam" << endl;
    //Traiter ici l'event Camera Indispo
    //return -1;
  }



  //Capture a temporary image from the camera
	Mat imgTmp;
	capture >> imgTmp;

  //Create a black image with the size as the camera output
	Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;

	Mat imgOriginal;
	Mat imgHSV;
	Mat imgThresholded;
	vector<vector<Point2f> > squares;
	Mat imgThresholded_colored;

  while (capture.isOpened())
  {
	usleep(1000);
    if(capture.isOpened()){
  		for (int i=0; i<5; i++){
  			capture >> imgOriginal;
  		}
	}

	capture >> imgOriginal;
	imwrite("imgori.jpg", imgOriginal);
    positionVoiture posVoit = findTags(imgOriginal, squares);

    //Faire les affectations de valeurs ici
    if (squares.size() != 0){

    	*(linkPositionVoiture()) = posVoit;
    	cout << "La voiture : " << endl
		<< "Distance : " << posVoit.dist << " cm"<< endl
		<< "Cote : " << posVoit.side << endl
		<< "Pourcentage :" << posVoit.percentageSide << endl;
    	depth = posVoit.dist;
	} else {
		initCarPosition();
		depth = 1000;
		cout << "No Car Detected" << endl;
	}

    if(depth < 150){
    	*(linkCameraSpeedLimit()) = 11;
    }
    else if(depth < 1000)
    {
    	*(linkCameraSpeedLimit()) = 60;
    }
    else {
    	*(linkCameraSpeedLimit()) = 100;
    }
  }
}



