#pragma once
class Matrix
{
private:
	int** matrix;
public:
	Matrix() = default;
	int** get_matrix();
	void set_matrix(int**);
};

