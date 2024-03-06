#ifndef RESISTOR
#define RESISTOR
class resistor : public components
{
private:
    std::vector<complex> resistors;
    std::string connection;

public:
    resistor(const std::vector<complex>& res, std::string con) :
        resistors{ res }, connection{ con }
    {}

    ~resistor() {}

    
    complex info() override;
};
#endif