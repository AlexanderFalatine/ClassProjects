// Alexander Falatine
// 12/10/2023
// Item Frequency list from file Application


#include "ItemTracker.h"

int main() {
    // utilize try catch during main incase of errors in file or menu manipulation
    try {
        ItemTracker itemTracker;
        itemTracker.readInputFile("Inventory.txt");
        itemTracker.saveToBackupFile("frequency.dat");

        int choice;
        std::string searchItem;

        do {
            // print menu options
            std::cout << "Menu:" << std::endl;
            std::cout << "1. Search for item frequency" << std::endl;
            std::cout << "2. Print all items frequency" << std::endl;
            std::cout << "3. Print histogram" << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cout << "Enter your choice: ";
            std::cout << std::endl;
            // handle invalid input
            if (!(std::cin >> choice)) {
                std::cerr << "Invalid input. Please enter a valid integer." << std::endl;
                std::cin.clear(); // clear error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                continue; // restart the loop
            }
            // menu logic
            switch (choice) {
            case 1:
                std::cout << "Enter item name to search (case-sensative): ";
                std::cin >> searchItem;
                itemTracker.searchItemQuantity(searchItem);
                break;
            case 2:
                itemTracker.printAllItemsQuantity();
                break;
            case 3:
                itemTracker.printHistogram();
                break;
            case 4:
                std::cout << "Exiting the program. Saving data to backup file..." << std::endl;
                itemTracker.saveToBackupFile("frequency.dat");
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            }
        } while (choice != 4);
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
