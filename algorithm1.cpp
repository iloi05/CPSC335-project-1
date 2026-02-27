// Names: Ivy Loi, Homan Qiu, Richie Nguyen, Robert Gutierrez
// CPSC 335 Section 11
// Project 1: Algorithm 1
// 2/24/26
#include <iostream>
#include <vector>
#include <algorithm>



int swapSeat(std::vector<int>& row) {
    // for counting swaps
    int count = 0;
    // Loop through the row and check if each seat is in the correct order
    for (int i = 0; i < row.size() - 1; i++) {
        // Calculate the partner seat for the current seat
        int partner = row[i] ^ 1;
        // Get the next seat in the row
        int next = row[i + 1];
        // If the current seat is not in the correct order
        if (next != partner) {
            // Find the correct seat for the current passenger
            auto it = std::find(row.begin() + i + 2, row.end(), partner);
            if (it != row.end()) {
                // Swap the current seat with the correct seat
                std::iter_swap(row.begin() + i + 1, it);
                // Increment the swap count
                count++;
            }
        }
    }
    return count;
}
int main() {
    std::vector<int> sample1 = {0, 2, 1, 3};
    std::vector<int> sample2 = {3, 2, 0, 1};

    std::cout << "Sample 1: ";
    for (int seat : sample1) {
        std::cout << seat << " ";
    }
    std::cout << std::endl;
    std::cout << "Seat swapped for sample1: " << swapSeat(sample1) << std::endl;
    std::cout << "Sample 2: ";
    for (int seat : sample2) {
        std::cout << seat << " ";
    }
    std::cout << std::endl;
    std::cout << "Seat swapped for sample2: " << swapSeat(sample2) << std::endl;
    
   
    return 0;
}