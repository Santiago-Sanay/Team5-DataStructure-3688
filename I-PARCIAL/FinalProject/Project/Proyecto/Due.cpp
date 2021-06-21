#include "Due.h"
#include "List.h"

Due::Due(string new_date, string new_weekday, double new_mounthly_amount)
{

    this->date = new_date;
    this->weekday = new_weekday;
    this->mounthly_amount = new_mounthly_amount;
}

string Due::get_date()
{
    return date;
}

void Due::set_date(string   new_date)
{
    this->date = new_date;
}

string Due::get_weekday()
{
    return weekday;
}

void Due::set_weekday(string new_weekday)
{
    this->weekday = new_weekday;
}

double Due::get_mounthly_amount()
{
    return mounthly_amount;
}

void Due::set_mounthly_amount(double new_mounthly_amount)
{
    this->mounthly_amount = new_mounthly_amount;
}

string Due::to_string1()
{
    string cad = "{\"";

    cad += "date\"";

    cad += ":";
    cad += "\"";
    cad += date;
    cad += "\"";
    cad += ",";
    cad += "\"";
    cad += "weekday";
    cad += "\"";
    cad += ":";
    cad += "\"";
    cad += weekday;
    cad += "\"";
    cad += ",";
    cad += "\"";
    cad += "mounthly_amount";
    cad += "\"";
    cad += ":";
    //cad += "\"";
    cad += to_string(mounthly_amount);
    cad += "}";
    return cad;
}

Due Due::from_string_to_due(string data)
{

    string a, b, c;
    string date, weekday, mounthly_amount1;
    int pos1 = 0;
    int pos2 = 0;
    int pos3 = 0;
    pos1 = data.find(",", 0);
    pos2 = data.find(",", pos1 + 1);
    pos3 = data.find("}", pos2 + 1);
    a = data.substr(0, pos1);
    b = data.substr(pos1 + 1, pos2 - pos1 - 1);
    c = data.substr(pos2 + 1, pos3 - pos2 - 1);
    pos1 = a.find(":", 0);
    date = a.substr(pos1 + 1, a.length() - pos1 - 1);
    date = date.replace(date.find("\"", 0), 1, "");
    date = date.replace(date.find("\"", 0), 1, "");
    pos2 = b.find(":", 0);
    weekday = b.substr(pos2 + 1, b.length() - pos2 - 1);
    weekday = weekday.replace(weekday.find("\"", 0), 1, "");
    weekday = weekday.replace(weekday.find("\"", 0), 1, "");
    pos3 = c.find(":", 0);
    mounthly_amount1 = c.substr(pos3 + 1, c.length() - pos3 - 1);

    cout << date << endl;
    cout << weekday << endl;
    cout << mounthly_amount1 << endl;

    return Due(date, weekday, stod(mounthly_amount1));
}