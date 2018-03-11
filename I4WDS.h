#pragma once
#include <math.h>

class I4WDS {//independent 4 wheel drive steering
private:
  double R;
  double input_dats[3];
public:
  I4WDS(double R){ this -> R = R; }
  void update(double X_coordinate, double Y_coordinate, double Angle){
    input_dats[0] = X_coordinate;
    input_dats[1] = Y_coordinate;
    input_dats[2] = Angle;
  }
  double Velout_1(){}
  double Velout_2(){}
  double Velout_3(){}
  double Velout_4(){}

  double Angout_1(){}
  double Angout_2(){}
  double Angout_3(){}
  double Angout_4(){}
};
