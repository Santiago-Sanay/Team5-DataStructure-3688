#include "Angle.h"

Angle::Angle(double new_grade_angle)
{
    this->grade_angle = new_grade_angle;
}

void Angle::set_grade_angle(double new_grade_angle)
{
    this->grade_angle = new_grade_angle;
}

double Angle::get_grade_angle()
{
    return grade_angle;
}

Angle::~Angle()
{
    
}
