#include circuit_impedance.h
complex info(complex r, double w, complex c, complex l) override
{
    //complex j = { 0, -1 };
    //double im_Z = (1 / (w * l)) - (1 / (w * c));
    //double re_Z = r;
    complex res_l = complex{ w,0 } *l;
    complex res_c = complex{ 1,0 } / (complex{ w,0 } *c);
    complex x_l = res_c;
    complex x_c = complex{ -1,0 } *res_c;
    //complex x_c = complex{ 0, 1 } / (complex{ 0,w } *l);
    complex z = r + (x_l - x_c);
    return z;
    //complex z_r = complex{ r, w * l } / complex{ (1 - pow(w,2) * c * l), r * c };
    //complex z_c = complex{ r, (w * l - (1 / w * c)) };
    //complex z_l = complex{ r, w * l } / complex{ (1 - pow(w,2) * c * l), r * c };


}