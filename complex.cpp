#include complex.h
void set_re(double r) { re = r; }

void set_im(double i) { im = i; }

double get_Re() const { return re; }// Return real component

double get_Im() const { return im; } // Return imaginary component

// Return modulus

double get_mod() const
{
    double mod = sqrt(
        (pow(re, 2) + pow(im, 2)));
    return mod;
}

// Return argument
double get_arg() const
{
    double arg = atan2(im, re);
    return arg;
}

// Return complex conjugate
complex get_cc() const
{
    complex cc{ re, -im };
    return cc;
}

// Overload + operator for addition
complex operator+(const complex& z) const
{
    complex temp{ re + z.re, im + z.im };
    return temp;
}

// Overload - operator for addition
complex operator-(const complex& z) const
{
    complex temp{ re - z.re, im - z.im };
    return temp;
}

// Function to calculate product of two complex numbers
complex operator*(const complex& z) const
{
    complex temp{ re * z.re + im * z.im, re * z.im + im * z.re };
    return temp;
}

complex operator/(const complex& z) const
{
    double temp_im = im * (-1);
    complex temp{ (re * z.re - im * z.im) / get_mod(), (re * z.im + im * z.re) / get_mod() };
    return temp;
}

friend std::ostream& operator << (std::ostream& os, const complex& z)
{

    if (z.im > 0)
    {
        os << z.re << "+" << z.im << "i";
    }

    else if (z.im < 0)
    {
        os << z.re << "" << z.im << "i";
    }
    return os;
}
