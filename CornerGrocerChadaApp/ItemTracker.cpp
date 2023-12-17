// Alexander Falatine
// 12/10/2023
// Item Frequency list from file Application


#include "ItemTracker.h"

void ItemTracker::readInputFile(const std::string& filename) {
    std::ifstream inputFile(filename); // open file
    if (!inputFile.is_open()) { // Error handle if file doesn't open
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::runtime_error("Error opening file"); 
    }

    std::string itemName; // local variable for item name in list

    while (inputFile >> itemName) { // iterate through the file to get the names of the items
        // Update total quantity
        itemQuantity[itemName]++;   // multiple items increase quantity

        // Update item set
        itemSets[itemName].insert(itemName);  // update the set of items created for main
    }

    if (inputFile.fail() && !inputFile.eof()) {  // error handling if reading the file goes wrong  
        std::cerr << "Error reading from file: " << filename << std::endl;
        throw std::runtime_error("Error reading from file");
    }

    inputFile.close(); // close the file
}

void ItemTracker::saveToBackupFile(const std::string& filename) { 
    std::ofstream backupFile(filename); // create file with given name as parameter
    if (!backupFile.is_open()) { // error handling for issues with writting to file
        std::cerr << "Error creating backup file: " << filename << std::endl;
        throw std::runtime_error("Error creating backup file");
    }

    for (const auto& pair : itemSets) { // for loop that copies all of the items stored in the previously created set
        backupFile << pair.first << " Quantity: " << itemQuantity[pair.first]
            << " Items: ";
        std::copy(pair.second.begin(), pair.second.end(),
            std::ostream_iterator<std::string>(backupFile, " "));
        backupFile << std::endl; 
    }

    backupFile.close(); // close the file
}

void ItemTracker::searchItemQuantity(const std::string& itemName) {
    auto it = itemQuantity.find(itemName); // search map for name of item
    if (it != itemQuantity.end()) { // if it isn't equal to itemQuantity.end (no item) the item is found
        std::cout << "Quantity of " << itemName << ": " << it->second << std::endl; // print the found item and quantity
    }
    else {
        std::cout << "Item not found in records." << std::endl; // if no item found print item not in records/file/map
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void ItemTracker::printAllItemsQuantity() {
    for (const auto& pair : itemQuantity) { // for all items in the item map
        std::cout << pair.first << " " << pair.second << std::endl; // print each item and their quantity
    }
    std::cout << std::endl; // give some room after for new menu iteration
    std::cout << std::endl;
}

void ItemTracker::printHistogram() { 
    for (const auto& pair : itemQuantity) { // for all items in item map
        std::cout << pair.first << " "; // print the item name
        for (int i = 0; i < pair.second; ++i) { // then print astrisks for each quantity in the item's map
            std::cout << "*";
        }
        std::cout << std::endl; // give some room after for new menu iteration
        std::cout << std::endl;
    }
}
