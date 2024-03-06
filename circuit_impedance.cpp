#include "complex.h"
#include "circuit.h"
complex info(complex r, double w, complex c, complex l) override 
{
    complex res_l = complex{ w,0 } *l;
    complex res_c = complex{ 1,0 } / (complex{ w,0 } *c);
    complex x_l = res_c;
    complex x_c = complex{ -1,0 } *res_c;
    complex z = r + (x_l - x_c);
    return z;
}