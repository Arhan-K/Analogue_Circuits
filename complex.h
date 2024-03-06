#ifndef COMPLEX
#define COMPLEX
#include <vector>
#include <iostream>
class complex
{
    friend complex operator+(double scalar, const complex & v);
    friend std::ostream& operator<<(std::ostream& os, const complex& z);

private:
    double re, im;

public:
    complex() : //default constructor
        re{}, im{}
    {}

    complex(double r, double i) : //parameterised constructor
        re{ r }, im{ i }
    {}

    ~complex() {} //destructor

    void set_re(double r) { re = r; }

    void set_im(double i) { im = i; }

    double get_Re() const { return re; }// Return real component

    double get_Im() const { return im; } // Return imaginary component

    double get_mod() const; // Return modulus
    
    double get_arg() const; // Return argument
    
    complex operator+(const complex& z) const;
    
    complex operator-(const complex& z) const;
    
    complex operator*(const complex& z) const;
    
    complex operator/(const complex& z) const;

    friend std::ostream& operator << (std::ostream& os, const complex& z);
    
};
#endif