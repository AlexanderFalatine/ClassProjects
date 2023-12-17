// Alexander Falatine
// 12/10/2023
// Item Frequency list from file Application


#ifndef ITEMTRACKER_H
#define ITEMTRACKER_H

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <iterator>
#include <stdexcept>

class ItemTracker {
private:
    std::map<std::string, int> itemQuantity;  // To store the total quantity of each item
    std::map<std::string, std::set<std::string>> itemSets;  // To store sets of unique items

public:
    void readInputFile(const std::string& filename);  // Function to read items from a file and update quantities and sets
    void saveToBackupFile(const std::string& filename);  // Function to save quantities and sets to a backup file
    void searchItemQuantity(const std::string& itemName);  // Function to search and display quantity of a specific item
    void printAllItemsQuantity();  // Function to print the quantity of all items
    void printHistogram();  // Function to print a histogram of item quantities
};

#endif // ITEMTRACKER_H