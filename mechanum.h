class mechanum
{
private:
  double wheel_radius;
  double input_dats[3];
  double status_dats[3][4];
  double velocity[4];
public:
  //arg is size
  mechanum(double width, double length, double wheel_radius);
  //arg is delta coordinates and angle
  void update(double X_coordinate,double Y_coordinate,double angle);
  //output is angular velocity
  double output_0(){return velocity[0] / wheel_radius;}
  double output_1(){return velocity[1] / wheel_radius;}
  double output_2(){return velocity[2] / wheel_radius;}
  double output_3(){return velocity[3] / wheel_radius;}
};

inline mechanum::mechanum(double width, double length, double wheel_radius){
  this -> wheel_radius = wheel_radius;
  status_dats[0][0] = -1.0;
  status_dats[0][1] =  1.0;
  status_dats[0][2] = -1.0;
  status_dats[0][3] =  1.0;
  status_dats[1][0] =  1.0;
  status_dats[1][1] =  1.0;
  status_dats[1][2] =  1.0;
  status_dats[1][3] =  1.0;
  status_dats[2][0] = width + length;
  status_dats[2][1] = -(width + length);
  status_dats[2][2] = -(width + length);
  status_dats[2][3] = width + length;
}
inline void mechanum::update(double X_coordinate,double Y_coordinate,double angle){
  input_dats[0] = X_coordinate;
  input_dats[1] = Y_coordinate;
  input_dats[2] = angle;
velocity[0] = status_dats[0][0] * input_dats[0] + status_dats[1][0] * input_dats[1] + status_dats[2][0] * input_dats[2];
  velocity[1] = status_dats[0][1] * input_dats[0] + status_dats[1][1] * input_dats[1] + status_dats[2][1] * input_dats[2];
  velocity[2] = status_dats[0][2] * input_dats[0] + status_dats[1][2] * input_dats[1] + status_dats[2][2] * input_dats[2];
  velocity[3] = status_dats[0][3] * input_dats[0] + status_dats[1][3] * input_dats[1] + status_dats[2][3] * input_dats[2];
}
