// Find min capacity to ship packages in 'D' days (Striver's YT: https://www.youtube.com/watch?v=MG-Ac4TAvTY)

#include <iostream>
#include <numeric>
using namespace std;

int count_days_for_given_capacity(vector<int> &arr, int capacity) {
    int days = 1;
    int load = 0;
    for(auto i: arr) {
        if(i + load > capacity) {
            days += 1;
            load = i;
        } else
            load += i;
    }
    return days;
}

/**
 * Approach: Optimal
 * - The 'min' capacity has to be max ele of the array.
 * - The 'max' capacity can be 'sum' of all elements of the array.
 * - Hence, we'll use binary search to find total 'days' required for each capacity
 * between 'min' and 'max' capacity.
 */
int min_capacity_to_ship(vector<int> &arr, int d) {
    int low = *max_element(arr.begin(), arr.end()); // max of array
    int high = accumulate(arr.begin(), arr.end(), 0); // sum of array elements

    while(low <= high) {
        int mid = (low + high) / 2;
        if(count_days_for_given_capacity(arr, mid) <= d)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int d = 5;
    cout << "Min capacity:\n" << min_capacity_to_ship(weights, d) << endl;
    return 0;
}