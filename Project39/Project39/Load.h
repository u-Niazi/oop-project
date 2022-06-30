#pragma once
#include"shipping_item.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<string>
class Load
{
private:
	vector<ShippingItem>* v = new vector<ShippingItem>;

	int current_index_item, count;
	double total_weight, total_volume;
	ShippingItem *storing_obj;
public:
	Load();
	~Load();
	int get_count() const { return count; }
	double get_total_volume() const { return total_volume;}
	double get_total_weight() const { return total_weight; }

	void FillLoad(std::string filename);
	void DisplayNextDelivery(std::ofstream & out) const;
	void ItemDelivered();
	void NotDeliverable();
	int HowManyDelivered() const;
	int HowManyNotDelivered() const;
};

