#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class omuni
{
private:
  double wheel_radius;
  double input_dats[3];
  double status_dats[3][3];
  double velocity[3];
public:
  omuni(double wheel_radiusm);
  void update(double X_coordinate, double Y_coordinate, double angle);
  double output_0(){return velocity[0] / wheel_radius;}//front
  double output_1(){return velocity[1] / wheel_radius;}//left rear
  double output_2(){return velocity[2] / wheel_radius;}//right rear
};

inline omuni::omuni(double wheel_radius, double L, double Alpha){
  this -> wheel_radius = wheel_radius;
  status_dats[0][0] = -sin(Alpha);
  status_dats[0][1] = -sin(Alpha + 2/3*M_PI);
  status_dats[0][2] = -sin(Alpha - 2/3*M_PI);
  status_dats[1][0] =  cos(Alpha);
  status_dats[1][1] =  cos(Alpha + 2/3*M_PI);
  status_dats[1][2] =  cos(Alpha - 2/3*M_PI);
  status_dats[2][0] =  L;
  status_dats[2][1] =  L;
  status_dats[2][2] =  L;
}

inline omuni::update(double X_coordinate, double Y_coordinate, double angle){
  input_dats[0] = X_coordinate;
  input_dats[1] = Y_coordinate;
  input_dats[2] = angle;
  velocity[0] = status_dats[0][0] * input_dats[0] + status_dats[1][0] * input_dats[1] + status_dats[2][0] * input_dats[2];
  velocity[1] = status_dats[0][1] * input_dats[0] + status_dats[1][1] * input_dats[1] + status_dats[2][1] * input_dats[2];
  velocity[2] = status_dats[0][2] * input_dats[0] + status_dats[1][2] * input_dats[1] + status_dats[2][2] * input_dats[2];
}
