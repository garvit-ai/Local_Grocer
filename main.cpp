#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Define a struct to store grocery item data
struct GroceryItem {
    string itemName;
    string storeName;
    double price;
};

// Initialize grocery items with predefined data
vector<GroceryItem> initializeGroceryItems() {
    return vector<GroceryItem> {
        {"Milk", "Store A", 2.99},
        {"Milk", "Store B", 2.89},
        {"Milk", "Store C", 2.95},
        {"Bread", "Store A", 1.99},
        {"Bread", "Store B", 1.89},
        {"Eggs", "Store C", 2.50},
        {"Eggs", "Store A", 2.40},
        {"Butter", "Store B", 0.99},
        {"Butter", "Store A", 0.95},
        {"Cheese", "Store C", 3.45}
    };
}

// Function to find and print the cheapest price for a specified item
void findCheapestPrice(const string& itemName, const vector<GroceryItem>& items) {
    double lowestPrice = numeric_limits<double>::max(); // Start with the highest possible number
    string cheapestStore;

    // Loop through the vector to find the cheapest price for the specified item
    for (const auto& item : items) {
        if (item.itemName == itemName && item.price < lowestPrice) {
            lowestPrice = item.price;
            cheapestStore = item.storeName;
        }
    }

    // Output the result
    if (cheapestStore.empty()) {
        cout << "Item not found." << endl;
    } else {
        cout << "Cheapest " << itemName << " is available at " << cheapestStore 
             << " for $" << lowestPrice << endl;
    }
}

// Main function to drive the program
int main() {
    vector<GroceryItem> groceryItems = initializeGroceryItems();
    string inputItem;

    // Prompt user for the item they are interested in
    cout << "Enter the name of the item to find the cheapest price: ";
    cin >> inputItem;

    // Search for and display the cheapest price for the item
    findCheapestPrice(inputItem, groceryItems);

    return 0;
}
