#ifndef INDUCTOR
#define INDUCTOR
class inductor : public components
{
private:
    std::vector<complex> inductors;
    std::string connection;

public:
    inductor(const std::vector<complex>& ind, std::string con) :
        inductors{ ind }, connection{ con }
    {}

    ~inductor() {}


    complex info() override;
};
#endif