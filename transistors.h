#ifndef TRANSISTOR
#define TRANSISTOR
class resistor : public components
{
private:
    std::vector<complex> transistors;
    std::string connection;

public:
    resistor(const std::vector<complex>& tran, std::string con) :
        transistors{ tran }, connection{ con }
    {}

    ~resistor() { std::cout << "series_resistance destructor called" << std::endl; }


    complex info() override;
};
#endif