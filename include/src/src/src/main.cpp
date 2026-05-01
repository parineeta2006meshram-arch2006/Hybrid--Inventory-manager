#include <iostream>
#include "InventoryManager.cpp"

using namespace std;

int main() {
    InventoryManager manager;
    int choice;

    do {
        cout << "\n1 Add\n2 View\n3 Update\n4 Delete\n5 List\n6 Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: manager.addItem(); break;
            case 2: manager.viewItem(); break;
            case 3: manager.updateItem(); break;
            case 4: manager.deleteItem(); break;
            case 5: manager.listItems(); break;
        }

    } while (choice != 6);

    return 0;
}
