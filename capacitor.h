#ifndef CAPACITOR
#define CAPACITOR
class capacitor : public components
{
private:
    std::vector<complex> capacitors;
    std::string connection;

public:
    capacitor(const std::vector<complex>& cap, std::string con) :
        capacitors{ cap }, connection{ con }
    {}

    ~capacitor() { }


    complex info() override;
};
#endif