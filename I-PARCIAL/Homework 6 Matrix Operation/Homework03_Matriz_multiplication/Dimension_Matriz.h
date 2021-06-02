#pragma once
class Dimension_Matriz
{
private:
	
	int row_1;
	int column_1;
	int row_2;
	int column_2;
public:
	Dimension_Matriz(int, int, int, int);
	int get_row_1();
	void set_row_1(int);
	int get_row_2();
	void set_row_2(int);
	int get_column_1();
	void set_column_1(int);
	int get_column_2();
	void set_column_2(int);


};

