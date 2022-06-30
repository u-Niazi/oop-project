#include "Load.h"

Load::Load() {
	this->current_index_item = 0;
	this->count = 0;
	this->total_volume = 0;
	this->total_weight = 0;
}
void Load::FillLoad(std::string filename) {
	ifstream read;

	if (!read.is_open()) {
		std::cout << "file is not opened";
	}
	vector<ShippingItem>L_SH_vector;
	Address storing_address;
	getline(read, storing_address.name);
	getline(read, storing_address.street_address);
	getline(read, storing_address.city,' ');
	getline(read, storing_address.state,' ');
	getline(read, storing_address.zip);
	storing_obj->set_address(storing_address);

	count++;
	this->total_weight = get_total_weight();
	this->total_volume = get_total_volume();
}
Load::~Load() {
	delete[]v;
}
void Load::ItemDelivered() {
	storing_obj->set_delivered(true);
}
void Load::NotDeliverable() {
	storing_obj->set_delivered(false);
}
void Load::DisplayNextDelivery(std::ofstream& out) const {
	out << storing_obj->get_address().name << endl;
	out << storing_obj->get_address().street_address << endl;
	out << storing_obj->get_address().city <<", " << storing_obj->get_address().zip <<endl;
}
int Load::HowManyDelivered() const {
	int delieverd=0;
	for (int i = 0; i < count; i++)
	{
		if (storing_obj->get_delivered() == true) {
			delieverd++;
		}
	}
	return delieverd;
}
int Load::HowManyNotDelivered() const {
	int not_delievered = 0;
		for (int i = 0; i < count; i++)
		{
			if (storing_obj->get_delivered() == true) {
				not_delievered++;
			}
		}
	return not_delievered;
}