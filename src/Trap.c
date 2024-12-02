// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

TM m;
unityTM(&m);
translateTM(&m, Height-(Width - Width_orifice)/2, Width_orifice/2);
symbol("Trap_half", &m);
parameter("Width", Width);
parameter("Width_wall", Width_wall);
parameter("Width_orifice", Width_orifice);
parameter("Height", Height);
parameter("Height_orifice", Height_orifice);
parameter("Angle", Angle);
parameter("Layer", Layer);

scaleTM(&m, 0, 0, 1, -1);
symbol("Trap_half", &m);
parameter("Width", Width);
parameter("Width_wall", Width_wall);
parameter("Width_orifice", Width_orifice);
parameter("Height", Height);
parameter("Height_orifice", Height_orifice);
parameter("Angle", Angle);
parameter("Layer", Layer);

snapnode(0, 0, 180);
snapnode(Height + Height_orifice, 0, 0);