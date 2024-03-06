#include transistors.h
complex info() override
{
    double trans_tot = 0;
    double inv_trans_tot = 0;
    for (int i = 0; i < transistors.size(); i++)
    {
        if (connection == "series")
        {
            trans_tot = trans_tot + transistors[i].get_Im();
        }
        else if (connection == "parallel")
        {
            for (int i = 0; i < transistors.size(); i++)
            {

                inv_trans_tot = inv_trans_tot + (1 / transistors[i].get_Im());
            }
            trans_tot = (1 / inv_trans_tot);
        }

    }
    return complex{ 0,trans_tot };
}