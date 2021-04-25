#include <iostream>
#include "Store.h"


using namespace std;

void Store::save_to_file() {
    store.SaveFile("../data/store.xml");
}

Store::Store() {
    ifstream infile("../data/store.xml");
    infile.seekg(0, ios::end);
    if (infile.tellg() == 0) {
        infile.close();
        ofstream out_stream;
        out_stream.open("../data/store.xml");
        out_stream << "<products/>" << endl;
        out_stream.close();
    }

    // now load the file
    store.LoadFile("../data/store.xml");
    products = store.FirstChild();

    // note the already used ids
    XMLElement* product = products->FirstChildElement();
    vector<int> used_ids;
    while (product != NULL) {
        used_ids.push_back(stoi(product->FirstChildElement("id")->GetText()));
        product = product->NextSiblingElement();
    }
    urng = UniqueRandomNumberGenerator(used_ids);
}

void Store::add_product(Product p) {
    XMLElement* product = store.NewElement("product");

    XMLElement* id = product->InsertNewChildElement("id");
    id->SetText(urng.generate());

    XMLElement* name = product->InsertNewChildElement("name");
    name->SetText(p.name.c_str());

    XMLElement* price = product->InsertNewChildElement("price");
    price->SetText(p.price);

    XMLElement* description = product->InsertNewChildElement("description");
    description->SetText(p.description.c_str());

    XMLElement* image_url = product->InsertNewChildElement("image_url");
    image_url->SetText(p.image_url.c_str());

    products->InsertEndChild(product);

    save_to_file();
}

void Store::remove_product(int id) {
    XMLElement* product = products->FirstChildElement();
    while (product != NULL) {
        if (product->FirstChildElement("id")->GetText() == to_string(id)) {
            products->DeleteChild(product);
            break;
        }
        product = product->NextSiblingElement();
    }

    save_to_file();
}

void Store::show_products() {
    XMLElement* element = products->FirstChildElement();

    while (element != NULL) {
        Utils::print_product(
            stoi(element->FirstChildElement("id")->GetText()),
            element->FirstChildElement("name")->GetText(),
            stod(element->FirstChildElement("price")->GetText()),
            element->FirstChildElement("description")->GetText(),
            element->FirstChildElement("image_url")->GetText());

        element = element->NextSiblingElement();
    }
}

void Store::show_product(int id) {
    XMLElement* element = products->FirstChildElement();
    while (element != NULL) {
        if (stoi(element->FirstChildElement("id")->GetText()) == id) {
            Utils::print_product(
                stoi(element->FirstChildElement("id")->GetText()),
                element->FirstChildElement("name")->GetText(),
                stod(element->FirstChildElement("price")->GetText()),
                element->FirstChildElement("description")->GetText(),
                element->FirstChildElement("image_url")->GetText());
            break; // Has only one element with given ID, so break
        }

        element = element->NextSiblingElement();
    }
}

void Store::show_products(string part_name) {
    XMLElement* element = products->FirstChildElement();
    while (element != NULL) {
        if (Utils::to_upper_case(element->FirstChildElement("name")->GetText()).find(Utils::to_upper_case(part_name)) != string::npos) {
            Utils::print_product(
                stoi(element->FirstChildElement("id")->GetText()),
                element->FirstChildElement("name")->GetText(),
                stod(element->FirstChildElement("price")->GetText()),
                element->FirstChildElement("description")->GetText(),
                element->FirstChildElement("image_url")->GetText());
        }

        element = element->NextSiblingElement();
    }
}

void Store::edit_product(int id, map<string, string> updates) {
    XMLElement* element = products->FirstChildElement();
    while (element != NULL) {
        if (stoi(element->FirstChildElement("id")->GetText()) == id) {
            if (updates.count("name")) {
                element->FirstChildElement("name")->SetText(updates["name"].c_str());
            }

            if (updates.count("price")) {
                element->FirstChildElement("price")->SetText(updates["price"].c_str());
            }


            if (updates.count("description")) {
                element->FirstChildElement("description")->SetText(updates["description"].c_str());
            }

            if (updates.count("image_url")) {
                element->FirstChildElement("image_url")->SetText(updates["image_url"].c_str());
            }
        }

        element = element->NextSiblingElement();
    }

    save_to_file();
    cout << "Updated Product" << endl;
    show_product(id);
}