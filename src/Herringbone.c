// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double a_radians = M_PI * Angle / 180;
double arr[12];
arr[0] = 0;
arr[1] = -Width/6;
arr[2] = (2*Width)/(3*tan(a_radians));
arr[3] = Width/2;
arr[4] = (2*Width)/(3*tan(a_radians)) + Width_herringbone/sin(a_radians);
arr[5] = Width/2;
arr[6] = Width_herringbone*M_SQRT2*cos(a_radians - M_PI_4);
arr[7] = -Width/6 + Width_herringbone*M_SQRT2*sin(a_radians - M_PI_4);
arr[8] = Width*tan(a_radians)/3 + Width_herringbone/cos(a_radians);
arr[9] = -Width/2;
arr[10] = Width*tan(a_radians)/3;
arr[11] = -Width/2;

polygon(6, arr);                   
