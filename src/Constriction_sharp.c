// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double nodes[8];
nodes[0] = 0;
nodes[1] = -Width_in/2;
nodes[2] = 0;
nodes[3] = Width_in/2;
nodes[4] = Length;
nodes[5] = Width_out/2;
nodes[6] = Length;
nodes[7] = -Width_out/2;
polygon(4, nodes);
snapnode(0, 0, 180);
snapnode(Length, 0, 0);
