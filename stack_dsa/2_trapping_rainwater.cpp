/**
 * YouTube (Striver's): https://youtu.be/m18Hntz4go8?si=bTdnfJj7iJS1DL6e
 */

#include <iostream>
using namespace std;

/**
 * Approach: Optimal (2-Pointer)
 * 1. 
 */
int get_total_trapped_water_optimal(vector<int> &arr) {
    int n = arr.size();
    int total = 0;
    int leftMax = 0;
    int rightMax = 0;

    for(int i = 0; i < n; i++) {
        // Example arr: {1,0,1,0,2,1,0,1,5,2,2,1,4,1}
        int j = i + 1;
        if(j < n) rightMax = arr[j];
        while(j < n) { // find the maximum ele on right of 'curr' element
            if(arr[j] > rightMax)
                rightMax = arr[j];
            j++;
        }
        int water = min(leftMax, rightMax) - arr[i];
        water = water < 0 ? 0 : water; // if negative water, then make zero
        total += water;
        if(arr[i] >= leftMax) // re-assign leftMax
            leftMax = arr[i];
    }

    return total;
}

/**
 * Approach: Better (Using PrevMax and NextMax array)
 * 1. In this, we'll calculate the 'PreviousMax' array and 'NextMax' array in two passes.
 * 2. 'PrevoiusMax' will be calculated from 0 -> N-1 and 'NextMax' from N - 1 -> 0.
 * 2. While calculating the 'NextMax' array, we can calculate the total trapped water inline.
 */
int get_total_trapped_water_better(vector<int> &arr) { // Time Complexity: O(3N) -> O(N), Space Complexity: O(2N) -> O(N)
    int n = arr.size();
    int total = 0;
    vector<int> prevoiusMax(n), nextMax(n);
    int maxLeft = arr[0];
    for(int i = 0; i < n; i++) {
        // Example array: {1,0,1,0,2,1,0,1,5,2,2,1,4,1}
        if(arr[i] > maxLeft)
            maxLeft = arr[i];
        prevoiusMax[i] = maxLeft;
    }

    int maxRight = arr[n-1];
    for(int j = n - 1; j >= 0; j--) {
        if(arr[j] > maxRight)
            maxRight = arr[j];
        nextMax[j] = maxRight;
    }

    for(int i = 0; i < n; i++) { // can skip this loop and find 'total' in 2nd loop itself.
        total += min(prevoiusMax[i], nextMax[i]) - arr[i];
    }
    
    return total;
}


/**
 * Approach:
 * 1. We'll calculate maximum possible unit water trapped for each column.
 * 2. Find the max on 'left' and 'right'. * 3. If no maxLeft or maxRight possible, then assume 'ele' itself.
 * 3. Calculate difference of min(maxLeft, maxRight) and the 'ele' and sum it.
 */
int get_total_trapped_water_brute_force(vector<int> &arr) { // Time Complexity: O(N^2)
    int n = arr.size();
    int total = 0;
    for(int i = 0; i < n; i++) {
        int maxLeft, maxRight;
        maxLeft = maxRight = arr[i];
        for(int j = i-1; j >=0; j--) { // find maxLeft
            if(arr[j] > maxLeft)
                maxLeft = arr[j];
        }

        for(int k = i+1; k < n; k++) { // find maxRight
            if(arr[k] > maxRight)
                maxRight = arr[k];
        }
        total += min(maxLeft, maxRight) - arr[i];
    }

    return total;

}

int main() {
    vector<int> arr = {1,0,1,0,2,1,0,1,5,2,2,1,4,1};
    cout << "Trapped Water:\n" << get_total_trapped_water_brute_force(arr);
    cout << "\nTrapped Water (Better):\n" << get_total_trapped_water_better(arr);
    cout << "\nTrapped Water (Optimal):\n" << get_total_trapped_water_optimal(arr);
    return 0;
}