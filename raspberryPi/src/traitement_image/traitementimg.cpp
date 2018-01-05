#include "traitement_image/traitementimg.hpp"
#include "Interface/PosVoitInterface.h"


// helper function:
// finds a cosine of angle between vectors
// from pt0->pt1 and from pt0->pt2
static double angle( Point pt1, Point pt2, Point pt0 )
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

positionVoiture findSquares( const Mat& image, vector<vector<Point> >& squares )
{
  int thresh = 50, N = 11;
	positionVoiture returnValue;
    squares.clear();

    Mat pyr, timg, gray0(image.size(), CV_8U), gray;

    // down-scale and upscale the image to filter out the noise
    pyrDown(image, pyr, Size(image.cols/2, image.rows/2));
    pyrUp(pyr, timg, image.size());
    vector<vector<Point> > contours;

    // find squares in every color plane of the image
	bool flagSortie = false;
    for( int c = 0; c < 3; c++ )
    {
		if(flagSortie){
			break;
		}
        int ch[] = {c, 0};
        mixChannels(&timg, 1, &gray0, 1, ch, 1);

        // try several threshold levels
        for( int l = 0; l < N; l++ )
        {
			if(flagSortie){
				break;
			}
            // hack: use Canny instead of zero threshold level.
            // Canny helps to catch squares with gradient shading
            if( l == 0 )
            {
                // apply Canny. Take the upper threshold from slider
                // and set the lower to 0 (which forces edges merging)
                Canny(gray0, gray, 0, thresh, 5);
                // dilate canny output to remove potential
                // holes between edge segments
                dilate(gray, gray, Mat(), Point(-1,-1));
            }
            else
            {
                // apply threshold if l!=0:
                //     tgray(x,y) = gray(x,y) < (l+1)*255/N ? 255 : 0
                gray = gray0 >= (l+1)*255/N;
            }

            // find contours and store them all as a list
            findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

            vector<Point> approx;

            // test each contour

            for( size_t i = 0; i < contours.size(); i++ )
            {
				if(flagSortie){
					break;
				}
                // approximate contour with accuracy proportional
                // to the contour perimeter
                approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

                // square contours should have 4 vertices after approximation
                // relatively large area (to filter out noisy contours)
                // and be convex.
                // Note: absolute value of an area is used because
                // area may be positive or negative - in accordance with the
                // contour orientation
                if( approx.size() == 4 &&
                    fabs(contourArea(Mat(approx))) > 1000 &&
                    isContourConvex(Mat(approx)) )
                {
                    double maxCosine = 0;

                    for( int j = 2; j < 5; j++ )
                    {
                        // find the maximum cosine of the angle between joint edges
                        double cosine = fabs(angle(approx[j%4], approx[j-2], approx[j-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }

                    // if cosines of all angles are small
                    // (all angles are ~90 degree) then write quandrange
                    // vertices to resultant sequence
                    if( maxCosine < 0.3 )
                        squares.push_back(approx);
						vector<int> coordonneesY;
						for (size_t i=0; i<approx.size(); i++){
							coordonneesY.push_back(approx[i].y);
							//std::cout<<"Les coordonnées du point "<<i<<" sont : "<<approx[i]<<endl;
						}


						//Calcul du côté
						float centre = (float)(approx[0].x+approx[1].x+approx[2].x+approx[3].x)/4.0;
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
						//std::cout<<endl;
						flagSortie=true;
						break;

                }
            }
        }
    }
	return returnValue;
}



void threadTraitement(){
  //Open the capture device
  VideoCapture capture;
	capture.set(CV_CAP_PROP_BUFFERSIZE, 3);
  capture.open(0);
  if ( !capture.isOpened() )  // if not success, exit program
  {
    cout << "Cannot open the web cam" << endl;
    //Traiter ici l'event Camera Indispo
    //return -1;
  }

  //Valeurs du filtre de couleur
	int iLowH = 38;
	int iHighH = 100;
	int iLowS = 50;
	int iHighS = 150;
	int iLowV = 100;
	int iHighV = 255;

  //Capture a temporary image from the camera
	Mat imgTmp;
	capture >> imgTmp;
  //Create a black image with the size as the camera output
	Mat imgLines = Mat::zeros( imgTmp.size(), CV_8UC3 );;

	Mat imgOriginal;
	Mat imgHSV;
	Mat imgThresholded;
	vector<vector<Point> > squares;
	Mat imgThresholded_colored;

  while (capture.isOpened())
  {
    if(capture.isOpened()){
  		for (int i=0; i<5; i++){
  			capture >> imgOriginal;
  		}
		}

    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
  	inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image
    //morphological opening (removes small objects from the foreground)
  	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
  	dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
     //morphological closing (removes small holes from the foreground)
    dilate( imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
    erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

    cvtColor(imgThresholded, imgThresholded_colored, COLOR_GRAY2BGR);


    positionVoiture posVoit = findSquares(imgThresholded_colored, squares);
    //Faire les affectations de valeurs ici
    //*(linkPositionVoiture()) = findSquares(imgThresholded_colored, squares);

    if (squares.size() != 0){
    	*(linkPositionVoiture()) = posVoit;
    	cout << "La voiture : " << endl
		<< "Distance : " << posVoit.dist << " cm"<< endl
		<< "Cote : " << posVoit.side << endl
		<< "Pourcentage :" << posVoit.percentageSide << endl;
	} else {
		initCarPosition();
		cout << "No Car Detected" << endl;
	}
    }


    //return 0;


}
