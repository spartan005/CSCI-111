// Hexagon.cpp
// Version 2.0
#include "hexagon.h"
#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<numeric>
#include<limits>
#include<cstdlib> //for: atexit
using namespace std;


const double POINTS_PER_INCH=96.0;


struct Point {
  double x;
  double y;
  double inches;
  double deg;
  Point(double a, double b, double c, double in) : x(a), y(b), deg(c), inches(in){}
};

const double Pi=atan(1)*4;
const double DegPerRad=57.2957795;

static Point currentPoint(0.0,0.0,0.0/DegPerRad, 0.25);
static std::vector<Point> v;


void moveForward(double inches)
{
  double x,y;
  x=cos(currentPoint.deg)*POINTS_PER_INCH*inches;
  y=-sin(currentPoint.deg)*POINTS_PER_INCH*inches;
  v.push_back(Point(x,y,currentPoint.deg, inches));
  currentPoint.x=x;
  currentPoint.y=y;
}

void moveBackward(double inches)
{
  double x,y;
  x=cos(currentPoint.deg+Pi)*POINTS_PER_INCH*inches; //Add Pi Radians to reverse direction
  y=-sin(currentPoint.deg+Pi)*POINTS_PER_INCH*inches; //Add Pi Radians to reverse direction
  v.push_back(Point(x,y,currentPoint.deg, inches));
  currentPoint.x=x;
  currentPoint.y=y;
}

void turnRightBy(double deg)
{
  currentPoint.deg=(currentPoint.deg-deg/DegPerRad);

}

void turnLeftBy(double deg)
{
  currentPoint.deg=((currentPoint.deg+deg/DegPerRad));
}

static double ymax=0.0;//std::numeric_limits<double>::min();
static double ymin=0.0;//std::numeric_limits<double>::max();
static double xmax=0.0;//std::numeric_limits<double>::min();
static double xmin=0.0;//std::numeric_limits<double>::max();

double _yelem_min(double d, const Point& p)
{
  double newsum=d+p.y;
  ymin=(newsum < ymin) ? newsum : ymin;
  return newsum;
}

double _yelem_max(double d, const Point& p)
{
  double newsum=d+p.y;
  ymax=(newsum > ymax) ? newsum : ymax;
  return newsum;
}

double _xelem_min(double d, const Point& p)
{
  double newsum=d+p.x;
  xmin = (newsum < xmin) ? newsum : xmin;
  return newsum;
}

double _xelem_max(double d, const Point& p)
{
  double newsum=d+p.x;
  xmax=(newsum > xmax) ? newsum : xmax;
  return newsum;
}

static double verticalMarginInches=0.5*POINTS_PER_INCH;
static double horizontalMarginInches=0.5*POINTS_PER_INCH;



void printpage()
{
  // A hack. Use this iterator to compute the summed minimum of each axis
  std::accumulate(v.begin(), v.end(), 0.0, _yelem_min);
  std::accumulate(v.begin(), v.end(), 0.0, _yelem_max);
  std::accumulate(v.begin(), v.end(), 0.0, _xelem_min);
  std::accumulate(v.begin(), v.end(), 0.0, _xelem_max);

  double offx=0.0-xmin+horizontalMarginInches/2.0;
  double offy=0.0-ymin+verticalMarginInches/2.0;

  cout.precision(3);
  cout << fixed;

  cout << "<!DOCTYPE html>" << endl;
  cout << "<html>" << endl;
  cout << "<title>Hexagon Challenge!</title>" << endl;
  cout << "<body>" << endl;

  cout << "<svg width=\"" << xmax-xmin+horizontalMarginInches << "\" height=\"" << (ymax-ymin)+verticalMarginInches << "\">" << endl;


  cout << "<polyline points=\"";

  //starting point
  cout << offx << "," << offy << " ";
  for(int j=0; j<v.size(); ++j)
  {
    offx+=v[j].x;
    offy+=v[j].y;
    cout << offx << "," << offy << " ";
  }
  cout << '\"' << endl;
  cout << "style=\"fill:white;stroke:black;stroke-width:2\" />" << endl;
  cout << "</svg>" << endl;
  cout << "</body>" << endl;
  cout << "</html>" << endl;
}

class Wrapper {
  public:
    Wrapper() {atexit(printpage);}
};
static Wrapper w; //force the atexit function to be set up
