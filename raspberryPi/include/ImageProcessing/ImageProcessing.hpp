#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/aruco.hpp>



#include <iostream>
#include <math.h>
#ifndef TRAITEMENT_IMG_H
#define TRAITEMENT_IMG_H


#include <string.h>

using namespace cv;
using namespace std;


typedef struct positionVoiture
{
    int side; //0 -> left, 1->right
    int dist; //distance en cm
	float percentageSide; //
} positionVoiture;


//positionVoiture findSquares( const Mat& image, vector<vector<Point> >& squares );
positionVoiture findTags( const Mat& image, vector<vector<Point2f> >& squares );
void threadTraitement();


#endif
