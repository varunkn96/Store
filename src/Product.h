#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;
/*
 *  Product class with all the properties
 */
class Product {
public:
    Product(string name, double price, string description, string image_url);

    int id;
    string name;
    double price;
    string description;
    string image_url;
};
#endif// PRODUCT_H