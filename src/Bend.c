double a_radians = fabs(Angle)*M_PI/180.0;
double sign = (Angle>0) ? -1.0 : 1.0;
int num = 90;
double nodes[360];
double ri = Radius-Width/2;
double ro = Radius+Width/2;
int i;
double a = 0.0;
double astep = a_radians/(num-1);
for(i=0; i<num; i++) {
    nodes[2*i] = ri*sin(a);
    nodes[2*i+1] = sign*(ri*cos(a)-Radius);
    nodes[4*num-2-2*i] = ro*sin(a);
    nodes[4*num-2-2*i+1] = sign*(ro*cos(a)-Radius);
    a += astep;
}
polygon(2*num,nodes);
