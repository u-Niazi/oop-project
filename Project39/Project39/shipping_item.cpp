#include "shipping_item.h"
#include <iostream>

double ShippingItem::kMaxWeight = 70;
double ShippingItem::kMaxSize = 108;
double ShippingItem::kMinSize = .007;

// implementation of the getters
Address ShippingItem::get_address() const {
    return address;
}

double ShippingItem::get_weight() const {
    return weight;
}

double ShippingItem::get_length() const {
    return length;
}

bool ShippingItem::get_delivered() const {
    return delivered;
}

// implementation of the setters
void ShippingItem::set_address(Address address)
{
    this->address = address;
}

void ShippingItem::set_weight(double weight)
{
    try {
        if (weight >= 0 && weight <= kMaxWeight) {
            this->weight = weight;
        }
        else {
            throw std::out_of_range("weight is out of range!!!\n");
        }
    }
    catch (std::out_of_range& err) {
        cout << err.what();
    }
}

void ShippingItem::set_length(double length)
{
    try {
        if (length >= kMinSize && length <= kMaxSize) {
            this->length = length;
        }
        else {
            throw std::out_of_range("weight is out of range!!!\n");
        }
    }
    catch (std::out_of_range& err) {
        cout << err.what();
    }
}

void ShippingItem::set_delivered(bool delivered)
{
    set_delivered(delivered);
}

// default constructor
ShippingItem::ShippingItem() {
    this->address.name = "unknown";
    this->weight = 2;
    this->length = 12;
    this->delivered = false;
}

// non-default constructor
ShippingItem::ShippingItem(Address address, double weight, double length) {
    this->address = address;
    this->weight = weight;
    this->length = length;
    this->delivered = false;
}

// desturctor
ShippingItem::~ShippingItem() {};

// other methods
void ShippingItem::MarkDelivered()
{
    set_delivered(true);
}
