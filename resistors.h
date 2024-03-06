#ifndef COMPONENTS
#define COMPONENTS
class resistor : public components
{
private:
    std::vector<complex> resistors;
    std::string connection;

public:
    resistor(const std::vector<complex>& res, std::string con) :
        resistors{ res }, connection{ con }
    {}

    ~resistor() { std::cout << "series_resistance destructor called" << std::endl; }

    
    complex info() override;
};
#endif