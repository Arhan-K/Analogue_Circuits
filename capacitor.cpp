#include capacitor.h
complex info() override
{
    double cap_tot = 0;
    double inv_cap_tot = 0;
    for (int i = 0; i < capacitors.size(); i++)
    {
        if (connection == "parallel")
        {
            cap_tot = cap_tot + capacitors[i].get_Im();
        }
        else if (connection == "series")
        {
            for (int i = 0; i < capacitors.size(); i++)
            {

                inv_cap_tot = inv_cap_tot + (1 / capacitors[i].get_Im());
            }
            cap_tot = (1 / inv_cap_tot);
        }

    }
    return complex{ 0,cap_tot };
}