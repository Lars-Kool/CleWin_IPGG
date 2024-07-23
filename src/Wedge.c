// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double a_radians = fabs(Angle)*M_PI/180.0;
double sign = (Angle<0) ? -1.0 : 1.0;
double nodes[8];
nodes[0] = 0;
nodes[1] = -sign * Width/2;
nodes[2] = 0;
nodes[3] = sign * Width/2;
nodes[4] = sin(a_radians)*Width;
nodes[5] = sign * Width/2 - sign * cos(a_radians)*Width;
nodes[6] = tan(a_radians/2)*Width;
nodes[7] = sign * -Width/2;
polygon(4, nodes);
