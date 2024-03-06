#include inductors.h
complex info() override
{
    double ind_tot = 0;
    double inv_ind_tot = 0;
    for (int i = 0; i < inductors.size(); i++)
    {
        if (connection == "series")
        {
            ind_tot = ind_tot + inductors[i].get_Im();
        }
        else if (connection == "parallel")
        {
            for (int i = 0; i < inductors.size(); i++)
            {

                inv_ind_tot = inv_ind_tot + (1 / inductors[i].get_Im());
            }
            ind_tot = (1 / inv_ind_tot);
        }

    }
    return complex{ 0,ind_tot };
}
