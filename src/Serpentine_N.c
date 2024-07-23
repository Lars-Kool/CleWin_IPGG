// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double Radius = Width/2 + Spacing/2;

TM ms[100];
int i = 0;
for (i = 0; i < (int)N; i++) {
    unityTM(&ms[i]);
    if (i % 2 == 1) {
        rotateTM(&ms[i], 2*Radius + Width/2, 0, 180);
    }
    translateTM(&ms[i], (i/2) * 4 * Radius, 0);
    symbol("U-bend_smooth", &ms[i]);
    parameter("Width", Width);
    parameter("Height", Height/2);
    parameter("Spacing", Spacing);
    parameter("Layer", Layer);
}

for (i = 0; i < (int)N-1; i++) {
    if (i % 2 == 0) {
        rectangle(
            2*Radius + (i/2) * 4 * Radius,
            -Radius,
            2*Radius + Width + (i/2) * 4 * Radius,
            Radius);   
    }
    else {
        rectangle(
            4*Radius + (i/2) * 4 * Radius,
            -Radius,
            4*Radius + Width + (i/2) * 4 * Radius,
            Radius);
    }                           
}

snapnode(Width/2, Radius, 270);
if ((int)N % 2 == 1) {
    snapnode(2*Radius + ((int)N/2) * 4 * Radius + Width/2, Radius, 270);
}
else {
    snapnode(((int)N/2) * 4 * Radius + Width/2, -Radius, 90);
}
