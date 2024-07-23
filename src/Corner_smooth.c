// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double a_radians = fabs(Angle)*M_PI/180.0;
double sign = (Angle>0) ? -1.0 : 1.0;

TM m;
unityTM(&m);
symbol("Bend", &m);
parameter("Angle", Angle);
parameter("Width", Width);
parameter("Radius", Radius);
parameter("Layer", Layer);

snapnode(0,0,180);
snapnode(Radius*sin(a_radians),sign*(Radius*cos(a_radians)-Radius),Angle);
