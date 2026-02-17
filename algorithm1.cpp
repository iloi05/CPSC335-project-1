#include <iostream>
#include <list>
#include <cstdlib>

int main() {
    std::list<int> rowOne;
    std::list<int> rowTwo;
    int rOadd;
    int rTadd;
    int input;
    // Main menu allows user to see what they can do with the list
    std::cout << "Main Menu" << std::endl;
    /*Options 1 & 2 allow the user to add any 
    available number of couples*/
    std::cout << "1. Add to Row One" << std::endl;
    std::cout << "2. Add to Row Two" << std::endl;
    std::cout << "3. Display Rows" << std::endl;
    // Option 4 should allow user to swap any elements in the two lists
    std::cout << "4. Swap Rows" << std::endl;
    // option 5 exits the program
    std::cout << "5. Exit" << std::endl;

    std::cout << "Enter your choice: ";
    std::cin >> input;

    if (input == 1) {
        std::cout << "Enter a number to add to Row One: ";
        std::cin >> rOadd; // adding to row 1
        rowOne.push_back(rOadd);
    } else if (input == 2) {
        std::cout << "Enter a number to add to Row Two: ";
        std::cin >> rTadd; // adding to row 2
        rowTwo.push_back(rTadd);
    } else if (input == 3) { // display the two rows
        std::cout << "Row One: ";
        for (int num : rowOne) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        std::cout << "Row Two: ";
        for (int num : rowTwo) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } else if (input == 4) {
        // need to fix this
        rowOne.swap(rowTwo);
    } else if (input == 5) {
        std::cout << "Exiting..." << std::endl;
        return EXIT_SUCCESS
    } else { // need to find way to loop back to main menu if invalid input
        std::cout << "Invalid choice. Please try again." << std::endl;
    }
    return 0;
}