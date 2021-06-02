#include "Dimension_Matriz.h"
 Dimension_Matriz::Dimension_Matriz(int new_row_1, int new_column_1, int new_row_2, int new_column_2) {
     this->row_1 = new_row_1;
     this->row_2 = new_row_2;
     this->column_1 = new_column_1;
     this->column_2 = new_column_2;
}

int Dimension_Matriz::get_row_1()
{
    return row_1;
}

void Dimension_Matriz::set_row_1(int new_row_1)
{
    this->row_1 = new_row_1;
}

int Dimension_Matriz::get_row_2()
{
    return row_2;
}

void Dimension_Matriz::set_row_2(int new_row_2)
{
    this->row_2 = new_row_2;
}

int Dimension_Matriz::get_column_1()
{
    return column_1;
}

void Dimension_Matriz::set_column_1(int new_column_1)
{
    this->column_1 = new_column_1;
}

int Dimension_Matriz::get_column_2()
{
    return column_1;
}

void Dimension_Matriz::set_column_2(int new_column_2)
{
    this->column_2 = new_column_2;
}
