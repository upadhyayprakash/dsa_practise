/**
 * Maximize the min. distance between aggressive cows.
 * YouTube (Striver's): https://www.youtube.com/watch?v=R_Mfw4ew-Vo
 * Pattern: Binary Search on 'Answers'
 * Real-world Use-cases:
 *  - Relax the gap between visitor's appointment times. 
 */

#include <iostream>
using namespace std;

bool can_we_place_cows(vector<int> &arr, int k, int dist) {
    int count = 1;
    int last = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] - last >= dist) { // valid position
            count++;
            last = arr[i];
        }
    }
    if(count >= k) return true;
    else return false;
}

int get_max_distance_between_cows(vector<int> positions, int k) { // TC: O(N * Log2(maxEle - minEle)), SC: O(1)
    int low = 1;
    int high = *max_element(positions.begin(), positions.end()) - *min_element(positions.begin(), positions.end());

    while(low <= high) {
        int mid = (low + high) / 2;
        if(can_we_place_cows(positions, k, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}

int main() {
    vector<int> positions = {0,3,4,7,10,9};
    int k = 4;

    cout << "Maximized gap between cows:\n" << get_max_distance_between_cows(positions, k);
    return 0;
}