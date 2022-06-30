#pragma once
#include"shipping_item.h"
class Flat : public ShippingItem {
private:
	double height;
	double thickness;

public:
	Flat();
	Flat(Address address, double weight, double length, double height, double thickness);
	~Flat(){}
	double get_height() const { return height; }
	double get_thickness() const { return thickness; }
	void set_length(double length);
	void set_height(double height);
    void set_thickness(double thickness_);
	double Volume() const;
	void Display(std::ostream & out) const;
};

