#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <algorithm> 
#include <vector>
#include <map>

using namespace std;

/*
 *  Provides some utility functions used by other classes
 */
class Utils {
public:
    static map<string, string> get_value_map(vector<string>& params);

    static void print_product(int id, string name, double price, string description, string image_url);

    static void print_vector(vector<string>& v);

    static vector<string> split(string str, char del);

    static string to_upper_case(string input);
};
#endif//UTILS_H