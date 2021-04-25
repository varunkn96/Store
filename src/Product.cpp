#include <iostream>
#include "Product.h"

using namespace std;

Product::Product(string name, double price, string description, string image_url) {
    this->name = name;
    this->price = price;
    this->description = description;
    this->image_url = image_url;
}