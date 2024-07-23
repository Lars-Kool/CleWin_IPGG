// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double nodes[404];
double amp = (Width_in - Width_out) / 4;
double avg = (Width_in + Width_out) / 4;

int i = 0;
double dy = 0;
for (i = 0; i < 101; i++) {
    dy = amp * cos(i * M_PI / 100);
    nodes[2*i] = Length * i / 100;
    nodes[2*i+1] = avg + dy;
    nodes[403-2*i-1] = Length * i / 100;
    nodes[403-2*i] = - avg - dy;
}
polygon(202, nodes);
snapnode(0, 0, 180);
snapnode(Length, 0, 0);
