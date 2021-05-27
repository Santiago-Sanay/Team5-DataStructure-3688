/***********************************************************************
 * Module:  Vector.h
 * Author:  User
 * Modified: miércoles, 26 de mayo de 2021 21:55:40
 * Purpose: Declaration of the class Vector
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Vector_h)
#define __Class_Diagram_1_Vector_h

class Vector
{
public:
	float getX(void);
	void setX(float newX);
	float getY(void);
	void setY(float newY);
	float getZ(void);
	void setZ(float newZ);
	Vector(float xNew, float yNew, float zNew);
	~Vector();

protected:
private:
	float x;
	float y;
	float z;


};

#endif