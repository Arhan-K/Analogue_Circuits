#include diodes.h
complex info() override
{
    double v_di_tot = 0;
    double inv_v_di_tot = 0;
    for (int i = 0; i < diodes.size(); i++)
    {
        if (connection == "series")
        {
            v_di_tot = v_di_tot + diodes[i].get_Im();
        }
        else if (connection == "parallel")
        {
            for (int i = 0; i < diodes.size(); i++)
            {

                inv_v_di_tot = inv_v_di_tot + (1 / diodes[i].get_Im());
            }
            v_di_tot = (1 / inv_v_di_tot);
        }

    }
    return complex{ 0, v_di_tot };
}