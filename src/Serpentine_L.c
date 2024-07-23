// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

char buff[100];
int N = 0;
if (Length_path < Length) {
    printf("Path is shorter than the length of the section, so a straight channel is built");
}
else {
    N = (int)ceil((Length - Length_path + Radius * (M_PI-2))/(-M_PI*Radius - Height));
    Height = -(Length - Length_path + Radius * (M_PI-2))/N + (4-M_PI)*Radius;
}

double length_straight = (Length - 2*Radius*(N + 1))/2;

TM m_straight;
unityTM(&m_straight);
symbol("Straight", &m_straight);
parameter("Width", Width);
parameter("Length", length_straight);
parameter("Layer", Layer);

translateTM(&m_straight, length_straight + 2*Radius*(N+1), 0);
symbol("Straight", &m_straight);
parameter("Width", Width);
parameter("Length", length_straight);
parameter("Layer", Layer);

TM m_corner;                                                   
unityTM(&m_corner);
translateTM(&m_corner, length_straight, 0);
symbol("Corner_smooth", &m_corner);
parameter("Width", Width);                            
parameter("Angle", 90);
parameter("Radius", Radius);
parameter("Layer", Layer);

TM m_corner2;
unityTM(&m_corner2);
if ((N%2) == 0) {
    scaleTM(&m_corner2, 0, 0, -1, -1); // if N is even, the channel comes from the bottom     
}
else {
    scaleTM(&m_corner2, 0, 0, -1, 1);
}
translateTM(&m_corner2, length_straight + 2*Radius*(N+1), 0);
symbol("Corner_smooth", &m_corner2);
parameter("Angle", 90);
parameter("Radius", Radius);
parameter("Layer", Layer);

TM m;
unityTM(&m);
translateTM(&m, length_straight + Radius - Width/2, 0);
symbol("Serpentine_N", &m);
parameter("Height", Height);
parameter("N", N);
parameter("Radius", Radius);
parameter("Width", Width);
parameter("Layer", Layer);
