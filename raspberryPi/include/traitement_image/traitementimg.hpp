#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

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

static double angle( Point pt1, Point pt2, Point pt0 );

positionVoiture findSquares( const Mat& image, vector<vector<Point> >& squares );

void threadTraitement();


#endif
