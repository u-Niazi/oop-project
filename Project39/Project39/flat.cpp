#include "flat.h"
#include "shipping_item.h"

#include<iostream>
#include "shipping_item.cpp"

void Flat::set_length(double length) {
	if (length < ShippingItem::kMinSize || length>15) {
		throw out_of_range("Length must be greater than zero");
	}
	this->length = length;
}
void Flat::set_height(double height) {
	if (height < ShippingItem::kMinSize || height > 12) {
		throw out_of_range("height must be greater than zero");
	}
	this->height = height;
}
void Flat::set_thickness(double thickness_) {
	if (thickness_ < ShippingItem::kMinSize || thickness_>0.75) {
		throw out_of_range("thickness must be greater than zero");
	}
	this->thickness = thickness;
}

Flat::Flat() {
	height = 8;
	thickness = 0.4;
}
Flat::Flat(Address address, double weight, double length, double height, double thickness) {
	this->address = address;
	this->weight = weight;
	this->length = length;

	this->set_length(this->length);
	this->set_height(this->height);
	this->set_thickness(this->thickness);
}
double Flat::Volume() const{
	return length * height * thickness;
}
void Flat::Display(std::ostream& out) const {
	cout << "Flat: " << get_weight() << " lbs." << get_length() << " x " << get_height() << " x " << get_thickness();
}