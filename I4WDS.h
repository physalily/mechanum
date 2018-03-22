#pragma once
#include <math.h>

class I4WDS {//independent 4 wheel drive steering
private:
  double R;
  double wheel_R;
  double cur_ang;
  double input_dats[3];
public:
  I4WDS(double R, double wheel_R, double cur_ang){
    this -> R = R;
    this -> wheel_R = wheel_R;
    this -> cur_ang = cur_ang;
  }
  void update(double X_coordinate, double Y_coordinate, double Angle){
    input_dats[0] = X_coordinate;
    input_dats[1] = Y_coordinate;
    input_dats[2] = Angle + cur_ang;
    cur_ang += Angle;
  }
  double Velout_1(){return sqrt(pow(input_dats[0] - R * input_dats * sin(cur_ang),2) + pow(input_dats[1] + R * input_dats[2] * sin(cur_ang)),2); }
  double Velout_2(){return sqrt(pow(input_dats[0] - R * input_dats * cos(cur_ang),2) + pow(input_dats[1] - R * input_dats[2] * sin(cur_ang)),2); }
  double Velout_3(){return sqrt(pow(input_dats[0] + R * input_dats * sin(cur_ang),2) + pow(input_dats[1] - R * input_dats[2] * cos(cur_ang)),2); }
  double Velout_4(){return sqrt(pow(input_dats[0] + R * input_dats * cos(cur_ang),2) + pow(input_dats[1] + R * input_dats[2] * sin(cur_ang)),2); }

  double Angout_1(){return atan((input_dats[1] + R * input_dats[2] * cos(cur_ang)) / (input_dats[0] - R * input_dats[2] * sin(cur_ang))); }
  double Angout_2(){return atan((input_dats[1] - R * input_dats[2] * sin(cur_ang)) / (input_dats[0] - R * input_dats[2] * cos(cur_ang))); }
  double Angout_3(){return atan((input_dats[1] - R * input_dats[2] * cos(cur_ang)) / (input_dats[0] + R * input_dats[2] * sin(cur_ang))); }
  double Angout_4(){return atan((input_dats[1] + R * input_dats[2] * sin(cur_ang)) / (input_dats[0] + R * input_dats[2] * cos(cur_ang))); }
};
