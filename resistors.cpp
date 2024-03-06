#include resistor.h
complex info() override
{
    double res_tot = 0;
    double inv_res_tot = 0;
    for (int i = 0; i < resistors.size(); i++)
    {
        if (connection == "series")
        {
            res_tot = res_tot + resistors[i].get_Re();
        }
        else if (connection == "parallel")
        {
            for (int i = 0; i < sizeof(resistors); i++)
            {
                inv_res_tot = inv_res_tot + (1 / resistors[i].get_Re());
            }
            res_tot = (1 / inv_res_tot);
        }
    }
    return complex{ res_tot,0 };
}
