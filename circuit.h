#ifndef CIRCUIT
#define CIRCUIT
class circuit {
public:
    ~circuit()
    {}
    virtual complex info(complex r, double w, complex c, complex l) = 0;
    //virtual void input_values() = 0;

};
#endif