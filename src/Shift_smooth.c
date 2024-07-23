// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double right_hand(double angle, double length, double height, double radius) {
    return (height - 2*radius*(1-cos(angle)))/(length - 2*radius*sin(angle));            
}

double find_angle(double length, double height, double radius, double precision) {
    double low = 0;
    double high = M_PI/2.01;
    double mid = (low+high)/2;
    while ((mid-low) > precision && (high-mid) > precision) {
        if (tan(mid) < right_hand(mid, length, height, radius)) {
            low = mid;
        }
        else {
            high = mid;
        }
        mid = (low+high)/2;
    }
    return mid;
}

double a_radians = find_angle(Length, Height, Radius, 0.0000001);
double a_degrees = a_radians/(2*M_PI)*360;

TM m_bend_1;
unityTM(&m_bend_1);
symbol("Corner_smooth", &m_bend_1);
parameter("Radius", Radius);
parameter("Width", Width);
parameter("Angle", -a_degrees);
parameter("Layer", Layer);

double length_rectangle = sqrt(pow(Length-2*Radius*sin(a_radians),2) + pow(Height-2*Radius*(1 - cos(a_radians)),2));
TM m_rectangle;
unityTM(&m_rectangle);
rotateTM(&m_rectangle, 0, 0, -a_degrees);
translateTM(&m_rectangle, Radius*sin(a_radians),Radius*cos(a_radians)-Radius);
symbol("Straight", &m_rectangle);
parameter("Length", length_rectangle);
parameter("Width", Width);
parameter("Layer", Layer);

TM m_bend_2;
unityTM(&m_bend_2);
rotateTM(&m_bend_2, 0, 0, -a_degrees);
translateTM(&m_bend_2, Length-Radius*sin(a_radians), -Height-(Radius*cos(a_radians)-Radius));
symbol("Corner_smooth", &m_bend_2);
parameter("Radius", Radius);
parameter("Width", Width);
parameter("Angle", a_degrees);
parameter("Layer", Layer);
