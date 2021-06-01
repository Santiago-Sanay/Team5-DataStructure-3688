#include "Calendar.h"

Calendar::Calendar(std::string dates[100])
{
    for (int i = 0; i < 100; i++) 
    {
        dates[i] = dates[i];
    }
}
 
void Calendar::set_date(std::string dates[100])
{
    for (int i = 0; i < 100; i++)
    {
        date[i] = dates[i];
    }
}

std::string* Calendar::get_date()
{
    return date;
}
