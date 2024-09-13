void get_tangent_parallel(double x1, double x2, double y1, double y2, bool above, double* output) {
    double sign = (above) ? 1.0 : -1.0;
    output[2] = atan2(y2-y1, x2-x1);
    output[0] = sign*Radius*sin(fabs(output[2]));
    output[1] = sign*Radius*cos(fabs(output[2]));
}

void get_tangent_diagonal(double x1, double x2, double y1, double y2, bool inverse, double* output) {
    // Based on https://math.stackexchange.com/questions/543496/how-to-find-the-equation-of-a-line-tangent-to-a-circle-that-passes-through-a-g
    double dx = (x2 - x1)/2, dy = (y2 - y1)/2;
    double dxr = -dy, dyr = dx;
    double d = sqrt(pow(dx,2) + pow(dy,2));
    double rho = Radius/d;
    double ad = pow(rho,2);   
    double bd = rho*sqrt(1-pow(rho,2));

    double Tx = (inverse) ? ad*dx - bd*dxr : ad*dx + bd*dxr;
    double Ty = (inverse) ? ad*dy - bd*dyr : ad*dy + bd*dyr;
    output[0] = Tx;
    output[1] = Ty;
    output[2] = atan2(dy-Ty, dx-Tx);
}

// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double a_radians_1 = M_PI * fabs(Angle_1)/180;
double a_radians_2 = M_PI * fabs(Angle_2)/180;

double sign_1 = (Angle_1 > 0) ? 1.0 : -1.0;
double x1 = -sign_1*Radius*sin(fabs(a_radians_1));
double y1 = -Radius*cos(fabs(a_radians_1));

double sign_2 = (Angle_2 > 0) ? 1.0 : -1.0;
double x2 = Length + sign_2*Radius*sin(a_radians_2);
double y2 = -Height + Radius*cos(a_radians_2);

double T[3] = {0,0,0};
get_tangent_diagonal(x1, x2, y1, y2, false, T);
double theta = 180*T[2]/M_PI;

bool diagonal = false;
double T2[3] = {0,0,0};
if (Angle_1 <= -theta && Angle_2 <= -theta) {
    diagonal = true;
    get_tangent_diagonal(x2, x1, y2, y1, false, T2);
}
else if (Angle_1 > -theta && Angle_2 <= -theta) {
    // Both nodes below center of circle
    x1 = Radius*sin(a_radians_1);
    y1 = Radius*cos(a_radians_1);
    get_tangent_parallel(x1, x2, y1, y2, false, T);
    theta = 180*T[2]/M_PI;
}
else if (Angle_1 <= -theta && Angle_2 > -theta) {
    // Both nodes above center of circle
    x2 = Length - Radius*sin(a_radians_2);
    y2 = -Height - Radius*cos(a_radians_2);
    get_tangent_parallel(x1, x2, y1, y2, true, T);
    theta = 180*T[2]/M_PI;
}
else {
    // Inverse diagonal
    diagonal = true;
    x1 = Radius*sin(a_radians_1);
    y1 = Radius*cos(a_radians_1);
    x2 = Length - Radius*sin(a_radians_2);
    y2 = -Height - Radius*cos(a_radians_2);
    get_tangent_diagonal(x1, x2, y1, y2, true, T);
    get_tangent_diagonal(x2, x1, y2, y1, true, T2);
    theta = 180*T[2]/M_PI;
}

double T1x = x1 + T[0];
double T1y = y1 + T[1];
double T2x = (diagonal) ? (x2 + T2[0]) : x2 + T[0];
double T2y = (diagonal) ? (y2 + T2[1]) : y2 + T[1];

snapnode(0,0,180-Angle_1);
snapnode(Length,-Height,-Angle_2);
snapnode(T1x, T1y, theta);
snapnode(T2x, T2y, 90-theta);

TM m;
unityTM(&m);
rotateTM(&m, 0, 0, -Angle_1);
symbol("Corner_smooth", &m);
parameter("Angle", theta + Angle_1);
parameter("Radius", Radius);
parameter("Width", 100);
parameter("Layer", Layer);

unityTM(&m);
rotateTM(&m, 0, 0, 180-Angle_2);
translateTM(&m, Length, -Height);
symbol("Corner_smooth", &m);
parameter("Angle", Angle_2+theta);
parameter("Radius", Radius);
parameter("Width", 100);
parameter("Layer", Layer);

unityTM(&m);
rotateTM(&m, 0, 0, theta);
translateTM(&m, T1x, T1y);
symbol("Straight", &m);
parameter("Width", 100);
parameter("Length", sqrt(pow(T2x-T1x,2) + pow(T2y-T1y,2)));
parameter("Layer", Layer);