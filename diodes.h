#ifndef DIODE
#define DIODE
class diode : public components
{
private:
    std::vector<complex> diodes;
    std::string connection;

public:
    diode(const std::vector<complex>& di, std::string con) :
        diodes{ di }, connection{ con }
    {}

    ~diode() { std::cout << "Diode destructor called" << std::endl; }

    complex info() override
};
#endif
