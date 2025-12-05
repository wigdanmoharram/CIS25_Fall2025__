#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    int id;
};

// Binary Search Function
int binarySearch(Item* arr, int size, int searchId) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid].id == searchId) {
            return mid; 
        } else if (arr[mid].id < searchId) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}

int main() {
    int SIZE = 100;

    // Dynamically allocate array
    Item* inventory = new Item[SIZE];

    // Populate sorted sample data
    for (int i = 0; i < SIZE; i++) {
        inventory[i].id = i + 1;  
        inventory[i].name = "Item_" + to_string(i + 1);
    }

    int searchId;
    cout << "Enter an ID to search (1–100): ";
    cin >> searchId;

    // Perform binary search
    int index = binarySearch(inventory, SIZE, searchId);

    if (index != -1) {
        cout << "Found! ID: " << inventory[index].id
             << ", Name: " << inventory[index].name << endl;
    } else {
        cout << "Item with ID " << searchId << " not found." << endl;
    }

    // Free the memory
    delete[] inventory;

    return 0;
}
