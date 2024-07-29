// Koko Eating Banana (Striver's YT: https://www.youtube.com/watch?v=qyfekrNni90)
// Pattern: Binary Search on 'Answers'
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int count_total_hours(vector<int> &arr, int capacity) {
    int total_hours = 0;
    for(auto i: arr) {
        /* 
        Here, 'double' type-casting is important or else 3/4 will become ceil(0), hence '0'
        With 'double', it'll be 3/4 -> ceil (0.75) -> 1, hence correct
        */
        total_hours += ceil((double)i/(double)capacity);
    }
    return total_hours;
}

int get_min_k_brute_force(vector<int> &arr, int h) { // Time Complexity: O(N * max(arr))
    int minK = 1;
    int maxEle = *max_element(arr.begin(), arr.end());
    while(minK <= maxEle) {
        if(count_total_hours(arr, minK) <= h)
            break;
        minK++;
    }
    return minK;
}

int get_min_k_optimal(vector<int> &arr, int h) { // Time Complexity: O(N * log2(max_of_arr))
    int maxEle = *max_element(arr.begin(), arr.end());

    int low = 1;
    int high = maxEle;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(count_total_hours(arr, mid) <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> arr = {3,6,7,11}; // piles of bananas
    int h = 8; // should be >= arr.size()
    cout << "Minimum 'k' for h = " << h  << "\n(Brute-force)" << endl;
    cout << get_min_k_brute_force(arr, h);

    cout << "\nMinimum 'k' for h = " << h << "\n(Optimal)\n";
    cout << get_min_k_brute_force(arr, h);
    return 0;
}