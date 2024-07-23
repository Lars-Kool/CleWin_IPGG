// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double Radius = Width/2 + Spacing/2;

rectangle(0, Radius, Width, Height - Radius - Width/2);
rectangle(2*Radius, Radius, 2*Radius + Width, Height - Radius - Width/2);

TM m;
unityTM(&m);
rotateTM(&m, 0, 0, 90);
translateTM(&m, 2*Radius + Width/2, Height - Radius - Width/2);
symbol("Corner_smooth", &m);
parameter("Width", Width);
parameter("Angle", 180);
parameter("Radius", Radius);
parameter("Layer", Layer);

snapnode(Width/2, Radius, 270);
snapnode(Width/2 + 2*Radius, Radius, 270);
