/**
 * Find single element in sorted array of double elements
 * YouTube(Striver's): https://www.youtube.com/watch?v=AZOmHuHadxQ
 * Pattern: Binary search on 1D
 */

#include <iostream>
using namespace std;

/**
 * Approach: Brute force
 * 1. Tarverse every alternate element and check with its next element.
 * 2. If equal, then move ahead.
 * 3. If not equal, then return arr[i] as result.
 */
int get_single_element_brute(vector<int> &arr) { // TC: O(N/2)
    if(arr.size() == 1) return arr[0];
    
    for(int i = 0; i < arr.size(); i += 2) {
        if(arr[i] != arr[i+1])
            return arr[i];
    }
}

/**
 * - Observation is that a duplicate pair can be found after every alternate index.
 * - Hence, in {0,0,1,1,2,2}, elements are paired at index {evenIdx, oddIdx}.
 * - If a single element is present somewhere in betwen, then after that position, every pair
 * will be paired at index {oddIdx, evenIdx}. We'll use this logic.
 * 
 * Approach: Optimal (Binary Search)
 * 0. Observation is that array will always be odd-lengthed.
 * 1. First, find the 'mid' element.
 * 2. If mid doesn't have its 'pair' in left and right then return the 'mid' as answer.
 * 3. If its 'pair' is in left sub-array, then check if remaining 'left' sub-array is even or odd.
 *      3.a If 'odd' lengthed, our target single elements lies in left subarray. (high = mid - 2)
 *      3.b If 'even' lengthed, our target lies in right subarray. (low = mid + 1)
 * 4. If mid's pair lies in right sub-array, check if remaining right subarray is even or odd.
 *      4.a If even, then target lies in left subarray (high = mid - 1)
 *      4.b If odd, then target lies in right subarray (low = mid + 2)
 */
int get_single_element_optimal(vector<int> &arr) {
    int low = 0;
    int high = arr.size() - 1;
    while(low < high) {
        int mid = (low + high) / 2;
        int ele = arr[mid];
        bool halvesAreEven = (high - mid) % 2 == 0;
        if(arr[mid + 1] == arr[mid]) {
            if(halvesAreEven)
                low = mid + 2;
            else
                high = mid - 1;
        } else if(arr[mid - 1] == arr[mid]) {
            if(halvesAreEven)
                high = mid - 2;
            else
                low = mid + 1;
        } else
            return arr[mid];
    }
    return arr[low];
}

int main() {
    vector<int> arr = {1,1,2,2,3,4,4,5,5,6,6};

    cout << "Single element:(brute):\n" << get_single_element_brute(arr);
    cout << "\nSingle element:(optimal):\n" << get_single_element_optimal(arr);
    return 0;
}