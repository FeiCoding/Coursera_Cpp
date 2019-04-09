#include <iostream>
#include <math.h>
using namespace std;

class CShape {
public:
	virtual double Area() = 0;
	virtual void Print() = 0;
};

class CCircle : public CShape {
	int radius;
public:
	CCircle(int radius) :radius(radius) {}
	virtual double Area();
	virtual void Print();
};

class CTriangle :public CShape {
	int l, m, n;
public:
	CTriangle(int l, int m, int n) :l(l), m(m), n(n) {}
	virtual double Area();
	virtual void Print();
};

class CRectangle :public CShape {
	int l, m;
public:
	CRectangle(int l, int m) :l(l), m(m) {}
	virtual double Area();
	virtual void Print();
};

double CCircle::Area() {
	return 2 * radius * atan(1) * 4;
}

void CCircle::Print() {
	cout << Area() << endl;
}

double CTriangle::Area() {
	return l + m + n;
}

void CTriangle::Print() {
	cout << Area() << endl;
}

double CRectangle::Area() {
	return 2 * (l + m);
}

void CRectangle::Print() {
	cout << Area() << endl;
}

int main() {
	cout << "Please Input the shape you want:" << endl;
	CShape * p = NULL;
	char c;
	
	
	
	cin >> c;
	switch (c)
	{
	case 'C':
		p = new CCircle(10);
		p->Print();
		break;

	case 'R':
		p = new CRectangle(10, 11);
		p->Print();
		break;

	case 'T':
	default:
		p = new CTriangle(10, 11, 12);
		p->Print();
		break;
	}
	return 0;
}