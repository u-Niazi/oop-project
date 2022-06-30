#include "Tube.h"

const double Tube::kPi = 3.14159;
void Tube::set_circumference(double circumference) {
	if (circumference<kMinSize || length + circumference>kMaxSize) {
		throw out_of_range("circumference must be greater than zero");
	}
	this->circumference = circumference;
}
Tube::Tube() {
	circumference = 12;
}
Tube::Tube(Address address, double weight, double length, double circumference) {
	this->address = address;
	this->weight = weight;
	this->length = length;
	try {
		this->set_circumference(this->circumference = circumference);
	}
	catch (out_of_range e) {
		throw;
	}
}
double Tube::Volume() const {
	return kPi * (circumference / 2 * kPi)*(circumference / 2 * kPi) * length;
}
double Tube::Girth() const {
	return circumference;
}
void Tube::Display(std::ostream& out) const {
	out << setprecision(1) << fixed;
	out << "Tube: " << get_weight() << " lbs. " << get_length() << " x " << get_circumference();
}