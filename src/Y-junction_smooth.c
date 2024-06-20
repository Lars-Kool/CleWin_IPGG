double a_rad_1 = fabs(Angle_1)*M_PI/180.0;
double a_rad_2 = fabs(Angle_2)*M_PI/180.0;

Radius_1 = Radius_1 < Width_out_1/2 ? Width_out_1/2 : Radius_1;
Radius_2 = Radius_2 < Width_out_2/2 ? Width_out_2/2 : Radius_2;

TM m1;
unityTM(&m1);
translateTM(&m1, 0, (Width_in - Width_out_1)/2);
symbol("Bend", &m1);
parameter("Width", Width_out_1);
parameter("Radius", Radius_1);
parameter("Angle", Angle_1);

TM m2;
unityTM(&m2);
translateTM(&m2, 0, -(Width_in - Width_out_2)/2);
symbol("Bend", &m2);
parameter("Width", Width_out_2);
parameter("Radius", Radius_2);
parameter("Angle", -Angle_2);

snapnode(0,0,180);
snapnode(
    Radius_1*sin(a_rad_1),
    Radius_1*(1-cos(a_rad_1)) + (Width_in - Width_out_1)/2,
    Angle_1);
snapnode(
    Radius_2*sin(a_rad_2),
    Radius_2*(cos(a_rad_2)-1) - (Width_in - Width_out_2)/2,
    -Angle_2);
