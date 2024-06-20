double a_rad_1 = fabs(Angle_1)*M_PI/180.0;
double a_rad_2 = fabs(Angle_2)*M_PI/180.0;
if (Width_out_1 < Width_out_2) {
    double temp = Width_out_1;
    Width_out_1 = Width_out_1 > Width_out_2 ? Width_out_1 : Width_out_2;
    Width_out_2 = temp;

    temp = Angle_1;
    Angle_1 = Angle_2;
    Angle_2 = temp;
}


TM m_1;
unityTM(&m_1);
translateTM(&m_1, 0, Width_in/2 - Width_out_1/2);
symbol("Wedge", &m_1);
parameter("Width", Width_out_1);
parameter("Angle", Angle_1);

double offset = Width_out_1 * tan(a_rad_1/2) - Width_out_2 * tan(a_rad_2/2);
TM m_2;
unityTM(&m_2);
translateTM(&m_2, offset, -Width_in/2 + Width_out_2/2);
symbol("Wedge", &m_2);
parameter("Width", Width_out_2);
parameter("Angle", -Angle_2);

rectangle(0, -Width_in/2, offset, -Width_in/2 + Width_out_2);

snapnode(0, 0, 180);
snapnode(
    sin(a_rad_1)*Width_out_1/2,
    Width_in/2 - cos(a_rad_1)*Width_out_1/2,
    Angle_1
);
snapnode(
    sin(a_rad_2)*Width_out_2/2 + offset,
    -Width_in/2 + cos(a_rad_2)*Width_out_2/2,
    -Angle_2
);
