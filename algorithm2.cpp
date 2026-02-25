// Names: Ivy Loi, Homan Qiu, Richie Nguyen, Robert Gutierrez
// CPSC 335 Section 11
// Project 1: Algorithm 2
// 2/24/26
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int getStartingCity(const vector<int>& cityDistances, 
    const vector<int>& fuel, const int& mpg) {
        int startingCity = 0;
        int tank = 0;
        int cities = static_cast<int>(cityDistances.size());

        for (int i = 0; i < cities - 1; i++) {
            // Calculate current Tank
            tank += fuel[i] * mpg;
            tank -= cityDistances[i];

            // Check if Tank is less than 0, if less go to next city
            if (tank < 0) {
                startingCity = i + 1;
                tank = 0;
            }
        }

        return startingCity;
}


int main() {
    vector<int> sampleDistances = {5, 25, 15, 10, 15};
    vector<int> sampleFuel = {1, 2, 1, 0, 3};
    int mpg = 10;

    int startingCity = getStartingCity(sampleDistances, sampleFuel, mpg);
    cout << "The preferred starting city is city " << startingCity << endl;

    return 0;
}




