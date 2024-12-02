// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double radius = (Width - Width_orifice)/2;
double nodes[192];
double a = 0.0;
int i;
for (i = 0; i < 91; i++) {
    nodes[2*i] = radius * cos(a);
    nodes[2*i+1] = radius * sin(a);
    a += M_PI/180;
}

double a_rad = M_PI * Angle / 180;
double b = (radius + Width_wall)/sin(a_rad);
double c = (radius + Width_wall)/cos(a_rad);
                    
nodes[182] = -(Height - radius);
nodes[183] = radius;
nodes[184] = -(Height - radius);
nodes[185] = radius + Width_wall;

nodes[186] = c * (b - Width_wall - radius) / b;         
nodes[187] = radius + Width_wall;

nodes[188] = radius + Height_orifice;
nodes[189] = b * (c - Height_orifice - radius) / c;


nodes[190] = radius + Height_orifice;
nodes[191] = 0;
polygon(96, nodes);      