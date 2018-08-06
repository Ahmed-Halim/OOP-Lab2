#include <iostream>
using namespace std;

class Circle {
protected:
	double radius; //circle radius
public:
	Circle() { radius = 0.0; } //default constructor
	~Circle() { } //default destructor
	Circle(double r)  //parametarize constructor
	{
		try {
			if (r >= 0)
				radius = r;
			else
				throw "Negative value is not accepted";
		}
		catch (const char *error) {
			cout << error << endl;
		}
	}
	void setradius(double r) {   //mutator function
		try { //exception handler
			if (r >= 0)
				radius = r;
			else
				throw "Negative value is not accepted"; //error message to display
		}
		catch (const char *error) {
			cout << error << endl;
		}
	}
	double getradius() { return radius; } //accessor function

	virtual void getArea() { cout << "Area = " << radius * radius * 3.14 << endl; } //virtual function for polymorphism

	Circle operator + (Circle &right) { //operator overloading that return object of type Circle
		Circle temp;   //temp object to hold left value
		temp = *this;    //assign temp object of left value
		temp.radius += right.radius;    //temp now = left + right
		return temp;
	}
};

class Cylinder : public Circle {
protected:
	double height;
public: 
	Cylinder() : Circle() { height = 0; } //default constructor
	~Cylinder() {  } //default destructor
	Cylinder(double r, double h) : Circle(r) { height = h; }  //parametarize constructor
	void setheight(double h) { height = h; }  //set height function
	double getheight() { return height; } //get height function
	void getArea() { cout << "The cylinder area = " << 2 * 3.14*radius*height + 2 * 3.14*radius*radius << endl; }  //get cylinder area function
};

void display(Circle& x) {
	x.getArea();
}

int main() {
	Circle cir1(4.5);  //create object cir1 with radius 4.5
	Circle cir2(6.5);  //create object cir2 with radius 6.5
	Circle cir3 = cir1 + cir2; //create object cir3 with radius = cir1 + cir2
	cir3.getArea(); //11*11*3.14

	Cylinder cyl1(3.5, 5.5);

	display(cyl1); //display Cylinder area

	Circle cir4(-2); //check exception handler


	system("pause");
}