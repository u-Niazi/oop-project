#pragma once
#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H
#include <string>
#include <fstream>
#endif
using namespace std;

struct Address {
public:
    string name;
    string street_address;
    string city;
    string state;
    string zip;
};

class ShippingItem {
protected:
    Address address;
    double weight;
    double length;
    bool delivered;

public:
    static double kMaxWeight;
    static double kMaxSize;
    static double kMinSize;

    // default constructor
    ShippingItem();

    // non-default constructor
    ShippingItem(Address address, double weight, double length);

    // destructor
    ~ShippingItem();

    //getters
    Address get_address() const;
    double get_weight() const;
    double get_length() const;
    bool get_delivered() const;

    // setters
    void set_address(Address address);
    void set_weight(double weight);
    virtual void set_length(double length);
    void set_delivered(bool delivered);

    // other methods
    void MarkDelivered();
    virtual double Volume() const = 0;
    virtual void Display(std::ostream& out) const = 0;






};



