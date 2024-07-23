// Set layer
char currLayer[100];
sprintf(currLayer, "#%i", (int)Layer);
layer(currLayer);

void sigmoid(double* x, int size) {
    int i = 0;
    x[0] = 0;
    x[size - 1] = 1;
    for (i = 1; i < size - 1; i++) {
        x[i] = 1 / (1 + exp(6 - (12 * (double)i / size)));
    }
}

void linspace(double* x, double start, double stop, int size) {
    double step = (stop - start) / ((double)size - 1);
    int i = 0;
    for (i = 0; i < size; i++) {
        x[i] = start + i * step;      
    }
}

void combineXY(double* x, double* y, double* nodes, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        nodes[2 * i] = x[i];
        nodes[2 * i + 1] = y[i];
    }
}

void scaleArray(double* array, double factor, double offset, int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        array[i] = array[i] * factor + offset;
    }
}

int size = 100;
double x[202];
double y[202];
linspace(x, 0, Length-Width/2, size);
sigmoid(y, 100);
scaleArray(y, Height, 0, size);

x[size] = Length;
y[size] = Height/2 + Width / 2;
int i = 0;
for (i = 0; i < size; i++) {
    x[i + size + 1] = x[size - i - 1] + Width/2;
    y[i + size + 1] = y[size - i - 1] - Width/2 - Height/2;
    y[size - i - 1] += Width/2 - Height/2;                          
}
x[2*size+1] = 0;
y[2*size+1] = -Width / 2 - Height/2;

double nodes[404];    
combineXY(x, y, nodes, 2*size+2);
polygon(2*size+2, nodes);
snapnode(0, -Height/2, 180);
snapnode(Length, Height/2, 0);
