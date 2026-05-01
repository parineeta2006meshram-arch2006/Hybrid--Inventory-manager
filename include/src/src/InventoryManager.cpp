#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/inventory.h"

using namespace std;

class InventoryManager {
public:

    void addItem() {
        Item item;
        item.is_deleted = 0;

        cout << "Enter ID: ";
        cin >> item.id;

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(item.name, 40);

        cout << "Enter Quantity: ";
        cin >> item.quantity;

        cout << "Enter Price: ";
        cin >> item.price;

        if (add_item(item))
            cout << "Item added successfully\n";
        else
            cout << "Error: Duplicate ID\n";
    }

    void viewItem() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        Item item;
        if (get_item(id, &item)) {
            cout << "ID: " << item.id << "\nName: " << item.name
                 << "\nQty: " << item.quantity << "\nPrice: " << item.price << endl;
        } else {
            cout << "Item not found\n";
        }
    }

    void updateItem() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;

        Item item;
        item.id = id;
        item.is_deleted = 0;

        cout << "Enter New Name: ";
        cin.ignore();
        cin.getline(item.name, 40);

        cout << "Enter New Quantity: ";
        cin >> item.quantity;

        cout << "Enter New Price: ";
        cin >> item.price;

        if (update_item(id, item))
            cout << "Updated successfully\n";
        else
            cout << "Item not found\n";
    }

    void deleteItem() {
        int id;
        cout << "Enter ID: ";
        cin >> id;

        if (delete_item(id))
            cout << "Deleted successfully\n";
        else
            cout << "Item not found\n";
    }

    void listItems() {
        vector<Item> items(100);

        int count = list_items(items.data(), 100);
        items.resize(count);

        sort(items.begin(), items.end(), [](Item a, Item b) {
            return a.id < b.id;
        });

        for (auto &item : items) {
            cout << item.id << " | " << item.name << " | "
                 << item.quantity << " | " << item.price << endl;
        }
    }
};
