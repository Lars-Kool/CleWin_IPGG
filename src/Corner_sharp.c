double a_radians = fabs(Angle)*M_PI/180.0;
double sign = (Angle<0) ? -1.0 : 1.0;
TM m;
unityTM(&m);
symbol("Wedge", &m);
parameter("Width", Width);
parameter("Angle", Angle);

snapnode(0, 0, 180);
snapnode(    
    sin(a_radians)*Width/2,
    sign * Width/2 - sign * cos(a_radians)*Width/2,
    Angle
);
