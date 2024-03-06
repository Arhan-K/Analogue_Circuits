// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include complex.h
#include components.h
#include resistor.h
#include capacitor.h
#include inductor.h
#include circuit.h

std::string validate(std::string s_p)
{
    std::string error;
    if (s_p != "series" && s_p != "parallel")
    {
        error = "Error! Unidentifiable message. Please type [series/ parallel]";
        //return false
        return error;
    }
    else
        return s_p;
}
bool double_validate(double num)
{
    if (std::isnan(num))
        return false;
    else
        return true;
}
bool int_validate(double n)
{
    bool flag = true;
    if (std::isnan(n) || std::cin.fail())
        flag = false;
    else
    {
        flag = true;
    }
    return flag;
}


int main()
{
    std::cout << "Run 119" << std::endl;
    double f; double i_0; double v_0;
    std::cout << "Enter the frequency of the alternating current in Hertz: " << std::endl;
    std::cin >> f;
    double omega = 2 * 3.14 * f;
    std::cout << "Enter the peak current: " << std::endl;
    std::cin >> i_0;
    std::cout << "Enter the peak voltage: " << std::endl;
    std::cin >> v_0;

    circuit* z = new circuit_impedance();
    components** circuit_components = new components * [3];
    int n_branches;
    std::string nest;
    /*std::cout << "Would you like to create a nested circuit?" << std::endl;
    std::cin >> nest;
    if (nest == "yes")
    {
        std::cout << "Do whole circuit rigmarole again" << std::endl;
    }
    std::cin >> n_branches;*/
    int n_r; int n_i; int n_c; //int n_d; int n_t;
    std::cout << "Enter the number of resistors: " << ::std::endl;
    std::cin >> n_r;
    std::vector<complex> resistor_vector(n_r);
    //std::shared_ptr<std::vector <complex>> res_list = std::make_shared < std::vector<complex>>(resistor_vector);
    //std::shared_ptr<std::vector<complex>> resistor_vector = std::make_shared<std::vector<complex>>();
    std::shared_ptr<complex> res_ptr = std::make_shared<complex>();
    std::string s_p_r; std::string s_p_i; std::string s_p_c;// std::string s_p_d; std::string s_p_t;
    if (n_r == 1)
    {
        s_p_r = "series";
        std::cout << "Enter the resistance of the resistor  in Ohms:" << std::endl;
        double r;
        std::cin >> r;
        complex{ r, 0 } = resistor_vector[0];
        //resistor_vector->push_back(complex{r,0});
        //res_list[0] = complex{ r,0 };
    }
    else
    {

        for (int i = 0; i < n_r; i++)
        {
            std::cout << "Enter the resistance of resistor " << i + 1 << " in Ohms:" << std::endl;
            double r;
            std::cin >> r;
            resistor_vector[i] = complex{ r,0 };
            //resistor_vector->push_back(complex{ r,0 });
            //complex z_r = z->info(complex{ r, 0 }, omega, complex{ 0, 0}, complex{ 0, 0 });
        }
        std::cout << "Would you like them connected in series or in parallel? Type [series/ parallel]: " << std::endl;
        std::cin >> s_p_r;
        while (validate(s_p_r) != s_p_r)
        {
            std::cout << validate(s_p_r) << std::endl;
            std::cin >> s_p_r;
        }
        circuit_components[0] = new resistor(resistor_vector, s_p_r);
        std::cout << s_p_r << " connection established for the resistors" << std::endl;
    }

    for (auto resistor_vector_it = resistor_vector.begin();
        resistor_vector_it < resistor_vector.end();
        ++resistor_vector_it) delete* resistor_vector_it;
    resistor_vector.clear();


    std::cout << "Enter the number of capacitors: " << ::std::endl;
    std::cin >> n_c;
    std::vector<complex> capacitor_vector(n_c);
    if (n_c == 1)
    {
        s_p_c = "parallel";
        std::cout << "Enter the capacitance of the capacitor  in Farads:" << std::endl;
        double c;
        std::cin >> c;
        capacitor_vector[0] = complex{ 0,c };
        //complex z_r = z->info(complex{ 0, 0 }, omega, capacitor_vector[0], complex{ 0, 0 });
    }
    else
    {

        for (int i = 0; i < n_c; i++)
        {
            double c;
            std::cout << "Enter the capacitance of capacitor " << i + 1 << " in Farads:" << std::endl;
            std::cin >> c;
            capacitor_vector[i] = complex{ 0,c };
            //complex z_r = z->info(complex{ 0, 0 }, omega, capacitor_vector[i], complex{ 0, 0 });
        }
        std::cout << "Would you like them connected in series or in parallel? Type [series/ parallel]: " << std::endl;
        std::cin >> s_p_c;
        while (validate(s_p_c) != s_p_c)
        {
            std::cout << validate(s_p_c) << std::endl;
            std::cin >> s_p_c;
        }
        circuit_components[1] = new capacitor(capacitor_vector, s_p_c);
        std::cout << s_p_c << " connection established for the capacitors" << std::endl;
    }

    //capacitor_vector.clear();
    for (auto capacitor_vector_it = capacitor_vector.begin();
        capacitor_vector_it < capacitor_vector.end();
        ++capacitor_vector_it) delete* capacitor_vector_it;
    capacitor_vector.clear();

    std::cout << "Enter the number of inductors: " << ::std::endl;
    std::cin >> n_i;
    std::vector<complex> inductor_vector(n_i);
    double ind;
    if (n_i == 1)
    {
        s_p_i = "series";
        std::cout << "Enter the inducitance of the inductor in Henrys:" << std::endl;

        std::cin >> ind;
        capacitor_vector[0] = complex{ 0, -ind };
        complex z_r = z->info(complex{ 0, 0 }, omega, complex{ 0, 0 }, inductor_vector[0]);
    }
    else
    {
        for (int i = 0; i < n_i; i++)
        {
            std::cout << "Enter the inductance of inductor " << i + 1 << " in Henrys:" << std::endl;
            std::cin >> ind;
            inductor_vector[i] = complex{ 0, ind };
            //complex z_r = z->info(complex{ 0, 0 }, omega, complex{ 0, 0 }, inductor_vector[i]);
        }

        std::cout << "Would you like them connected in series or in parallel? Type [series/ parallel]: " << std::endl;
        std::cin >> s_p_i;
        while (validate(s_p_i) != s_p_i)
        {
            std::cout << validate(s_p_i) << std::endl;
            std::cin >> s_p_i;
        }
        circuit_components[2] = new inductor(inductor_vector, s_p_i);
        std::cout << s_p_i << " connection established for the inductors" << std::endl;
    }

    //inductor_vector.clear();

    for (auto inductor_vector_it = inductor_vector.begin();
        inductor_vector_it < inductor_vector.end();
        ++inductor_vector_it) delete* inductor_vector_it;
    inductor_vector.clear();
    /*for (int i = 0; i < n_i; i++)
    {
        delete inductor_vector[i];
    }
    delete[] inductor_vector;*/

    /*std::cout << "Enter the number of diodes: " << ::std::endl;
    std::cin >> n_d;
    std::vector<complex> diode_vector(n_d);
    double v_di;
    if (n_d == 1)
    {
        s_p_d = "series";
        std::cout << "Enter the voltage drop of the diode in Volts:" << std::endl;

        std::cin >> v_di;
        diode_vector[0] = complex{ 0, -ind };
        //complex z_d = z->info(complex{ 0, 0 }, omega, complex{ 0, 0 }, diode_vector[0]);
    }
    else
    {
        for (int i = 0; i < n_d; i++)
        {
            std::cout << "Enter the voltage drop of diode " << i + 1 << " in Volts:" << std::endl;
            std::cin >> v_di;
            diode_vector[i] = complex{ 0, v_di };
            //complex z_r = z->info(complex{ 0, 0 }, omega, complex{ 0, 0 }, inductor_vector[i]);
        }

        std::cout << "Would you like them connected in series or in parallel? Type [series/ parallel]: " << std::endl;
        std::cin >> s_p_d;
        while (validate(s_p_d) != s_p_d)
        {
            std::cout << validate(s_p_d) << std::endl;
            std::cin >> s_p_d;
        }
        circuit_components[3] = new inductor(diode_vector, s_p_d);
        std::cout << s_p_i << " connection established for the diodes" << std::endl;
    }

    std::cout << "Enter the number of transistors: " << ::std::endl;
    std::cin >> n_t;
    std::vector<complex> transistor_vector(n_t);
    double t;
    if (n_t == 1)
    {
        s_p_t = "series";
        std::cout << "Enter the transistance of the transistor in ?:" << std::endl;

        std::cin >> t;
        diode_vector[0] = complex{ 0, t };
        complex z_d = z->info(complex{ 0, 0 }, omega, complex{ 0, 0 }, transistor_vector[0]);
    }
    else
    {
        for (int i = 0; i < n_d; i++)
        {
            std::cout << "Enter the transistor of transistor " << i + 1 << " in Volts:" << std::endl;
            std::cin >> t;
            transistor_vector[i] = complex{ 0, t };
            complex z_t = z->info(complex{ 0, 0 }, omega, complex{ 0, 0 }, transistor_vector[i]);
        }

        std::cout << "Would you like them connected in series or in parallel? Type [series/ parallel]: " << std::endl;
        std::cin >> s_p_t;
        while (validate(s_p_t) != s_p_t)
        {
            std::cout << validate(s_p_t) << std::endl;
            std::cin >> s_p_t;
        }
        circuit_components[4] = new inductor(transistor_vector, s_p_t);
        std::cout << s_p_t << " connection established for the transistors" << std::endl;
    }*/

    double i_rms = i_0 / sqrt(2);
    double v_rms = v_0 / sqrt(2);
    //double p_avg = i_rms * v_rms * cos(phi);
    std::cout << "Calculating impedance, phi etc...." << std::endl;
    complex R = circuit_components[0]->info();
    double X_R = R.get_Re();
    std::cout << "X_R calculated" << std::endl;
    complex C = circuit_components[1]->info();
    double X_C = 1 / (omega * C.get_Im());
    std::cout << "X_C calculated" << std::endl;
    complex L = circuit_components[2]->info();
    double X_L = omega * L.get_Im();
    std::cout << "X_L calculated" << std::endl;

    //circuit_components.clear()
    delete circuit_components[0];
    delete circuit_components[1];
    delete circuit_components[2];
    delete[] circuit_components;

    complex Z{ 0,0 };
    Z = z->info(R, omega, C, L);
    double phi = Z.get_arg();



    // Not printing past here
    double f_R = 1 / (2 * 3.14 * sqrt(L.get_Im() * C.get_Im()));
    std::cout << "The total resistance of the " << s_p_r << " connection is " << R.get_Re() <<
        " Ohms." << std::endl;
    std::cout << "The total capacitance of the " << s_p_c << " connection is " << C.get_Im() <<
        " Farads." << std::endl;
    std::cout << "The total impedance of the " << s_p_c << " capacitor connection is " << X_C <<
        " Ohms." << std::endl;
    std::cout << "The total inductance of the " << s_p_i << " connection is " << L.get_Im() <<
        " Henrys." << std::endl;
    std::cout << "The total impedance of the " << s_p_i << " inductor capacitor connection is " << X_L <<
        " Ohms." << std::endl;
    std::cout << "The resonant frequency of the circuit is " << f_R << " Henrys." << std::endl;
    std::cout << "The impedance of the circuit is Z = " << Z << "Ohms." << std::endl;
    std::cout << "The phase difference of the circuit is " << phi << " Radians." << std::endl;
    //std::cout << "The average Power is: " << p_avg << " Watts." << std::endl;


    /*for (int i = 0; i < n_r; i++)
    {
        delete resistor_vector[i];
    }*/
    //delete[] resistor_vector;


    //resistor_vector.clear();


    /*try
    {
        std::cout << "Hello World." << std::endl;

    }
    catch
    {
        std::cout << "" << std::endl;
    }*/


}
