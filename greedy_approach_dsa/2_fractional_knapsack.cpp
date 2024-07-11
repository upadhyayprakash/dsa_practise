// YouTube: https://youtu.be/F_DDzYnxO14?si=26_Mtv5QzCEFPTFR
#include <iostream>
#include <vector>
using namespace std;

double maximize_knapsack_value(int cap, vector<int> values, vector<int> weights) {
    double value = 0;
    // ToDo
    return value;

}

int main() {
    int numOfItems = 3;
    int capacity = 50; // knapsack capacity
    vector<int> values = {100,60,120};
    vector<int> weights = {20,10,30};
    cout << "Max Knapsack Value:\n" << maximize_knapsack_value(capacity, values, weights) << endl;
    return 0;
}