#pragma once
#include "shipping_item.h"
#include<iostream>
#include <cmath>
#include <iomanip>
class Tube:public ShippingItem
{
private:
	double circumference;
public:
	static const double kPi;

	Tube();
	Tube(Address address, double weight, double length, double circumference);
	~Tube(){}
	double get_circumference() const { return circumference; }
	void set_circumference(double circumference);
	double Volume() const;
	double Girth() const;
	void Display(std::ostream & out) const;

};


