// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

circle(0, 0, Radius);
rectangle(0, -Width/2, Radius, Width/2);
snapnode(Radius, 0, 0);
