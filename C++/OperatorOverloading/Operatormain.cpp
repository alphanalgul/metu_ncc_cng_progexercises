#include"OperatorHeader.h"

void operator!(Y y)
{
	cout << "Yvalue: " << y.Yval << endl;
}

void operator++(Y& y)
{
	y.Yval++;
}


void operator++(Y& y,int)
{
	cout << "Im post increment Y" << endl;
	y.Yval++;
}

Y operator+ (Y y1, Y y2)
{
	Y temp(0);
	temp.Yval = y1.Yval + y2.Yval;
	return temp;
}
int main()
{
	X x1(2);
	Y y1(12);
	
	++x1;
	++y1;

	x1++;
	y1++;
	
	!x1;
	!y1;

	!(x1 + x1);
	!(y1 + y1);
	cout << "\n----------------------------------\n" << endl;

	X x2(5),x3(0);
	Y y2(15),y3(0);

	x3 = x1 + x2;
	y3 = y1 + y2;

	!x3;
	!y3;

	cout << "\n----------------------------------\n" << endl;
	X x4(0);
	x4();
	!x4;
	x4(1);
	!x4;
	x4(1,2);
	!x4;
	x4(1,2,3);
	!x4;
	x4(3.14);
	!x4;

	return 0;
}
