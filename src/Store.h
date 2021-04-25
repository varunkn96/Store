#ifndef STORE_H
#define STORE_H

#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "../tinyxml2/tinyxml2.h"
#include "Product.h"
#include "UniqueRandomNumberGenerator.h"
#include "Utils.h"

using namespace tinyxml2;

/*
 *  Does the operations of add, remove, edit, show using tinyxml2 api and stores the data in data/store.xml
 */
class Store {
private:
    XMLDocument store;
    XMLNode* products;
    UniqueRandomNumberGenerator urng;
    void save_to_file();
public:
    Store();

    void add_product(Product p);

    void remove_product(int id);

    void show_products();

    void show_product(int id);

    void show_products(string part_name);

    void edit_product(int id, map<string, string> updates);
};
#endif// STORE_H