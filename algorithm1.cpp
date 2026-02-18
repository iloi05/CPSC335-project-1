#include <iostream>
#include <list>
#include <cstdlib>
#include <algorithm>
#include <iterator>

int main() {
    std::list<int> rowOne;
    std::list<int> rowTwo;
    int rOadd;
    int rTadd;
    int input;
    int swapOne;
    int swapTwo;
    while (true) {
        // Main menu allows user to see what they can do with the list
        std::cout << "Main Menu" << std::endl;
        std::cout << std::endl;
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
            continue;
        } else if (input == 2) {
            std::cout << "Enter a number to add to Row Two: ";
            std::cin >> rTadd; // adding to row 2
            rowTwo.push_back(rTadd);
            continue;
        } else if (input == 3) { // display the two rows
            // checking if both rows are empty, loop back to main menu if yes
            if (rowOne.empty() && rowTwo.empty()) {
                std::cout << "Both rows are empty." << std::endl;
                std::cout << "Add numbers to the rows to see them displayed." << std::endl;
                continue;
            }
            // checking if only 1 row is empty, will display whichever one isn't empty
            if (rowOne.empty() && !rowTwo.empty()) {
                std::cout << "Row One is empty." << std::endl;
            } else {
                std::cout << "Row One: ";
                for (int num : rowOne) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
            }
            if (rowTwo.empty() && !rowOne.empty()) {
                std::cout << "Row Two is empty." << std::endl;
            } else {
                std::cout << "Row Two: ";
                for (int num : rowTwo) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
            }
            continue;
        } else if (input == 4) {
            // checking if either row is empty, loop back to main menu if yes
            if (rowOne.empty() || rowTwo.empty()) {
                std::cout << "Both rows must have at least one number to swap. Please add numbers to both rows first." << std::endl;
                continue;
            } else {
            // have user enter a number from each row to swap, then swap the two numbers
                std::cout << "Which two numbers would you like to swap?" << std::endl;
                std::cout << "Enter the number from Row One: ";
                std::cin >> swapOne;
                std::cout << "Enter the number from Row Two: ";
                std::cin >> swapTwo;
                std::list<int>::iterator itOne = std::find(rowOne.begin(), rowOne.end(), swapOne);
                std::list<int>::iterator itTwo = std::find(rowTwo.begin(), rowTwo.end(), swapTwo);
                if (itOne != rowOne.end() && itTwo != rowTwo.end()) {
                    std::iter_swap(itOne, itTwo);
                } else {
                    std::cout << "One or both numbers not found. Please try again." << std::endl;
                }
                continue;
            }
        } else if (input == 5) {
            // exits program
            std::cout << "Exiting..." << std::endl;
            return EXIT_SUCCESS;
        } else { 
            // Invalid input loops back to start of menu
            std::cout << "Invalid choice. Please try again." << std::endl;
            continue;
        }
    }
    return 0;
}