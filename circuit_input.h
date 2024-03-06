#ifndef CIRCUIT_INPUT
#define CIRCUIT_INPUT

class circuit_input : public circuit
{
private:
    double peak_current;
    double peak_voltage;
    double angular_frequency;
    complex imp;

public:
    circuit_input(double I_0, double V_0, double omega, complex Z) :
        peak_current{ I_0 }, peak_voltage{ V_0 }, angular_frequency{ omega }, imp{ Z }
    {}

    ~circuit_input() {}
    double input_values()
    
    virtual complex info() = 0;
}; 
#endif
