// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

double angle = 45;
double a_radians = M_PI * angle / 180;
double d = (Width_herringbone+Spacing)/cos(a_radians);
int i = 0;
int j = 0;
TM m;
for (i = 0; i < N_groups; i++) {
    for (j = 0; j < N_per_group; j++) {
        unityTM(&m);
        if ((i%2) == 1) {
            scaleTM(&m, 0, 0, 1, -1);
        }
        translateTM(&m, (i*N_per_group + j)*d + i*Width/(3*tan(a_radians)), 0);
        symbol("Herringbone", &m);
        parameter("Angle", angle);
        parameter("Width", Width);
        parameter("Width_herringbone", Width_herringbone);
        parameter("Layer", Layer);
    }
}

snapnode(0, 0, 180);
snapnode(((i-1)*N_per_group + j - 1)*d + (i-1)*Width/(3*tan(a_radians)) +
    (2*Width)/(3*tan(a_radians)) +
    Width_herringbone/sin(a_radians),
    0, 0);
