// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

rectangle(0, -Width/2, Length, Width/2);
snapnode(0, 0, 180);
snapnode(Length, 0, 0);
snapnode(Length/2, Width/2, 90);
snapnode(Length/2, -Width/2, 270);
