#include <iostream>
#include <vector>
using namespace std;

int get_2nd_largest(vector<int> &arr, int n) {
    int largest = arr[0];
    int secLargest = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            secLargest = largest;
            largest = arr[i];
        } else if(arr[i] < largest && arr[i] > secLargest) {
            secLargest = arr[i];
        }
    }

    return secLargest;
}

int get_2nd_smallest(vector<int> &arr, int n) {
    int smallest = arr[0];
    int secSmallest = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            secSmallest = smallest;
            smallest = arr[i];
        } else if(arr[i] != smallest && arr[i] < secSmallest) {
            secSmallest = arr[i];
        }
    }

    return secSmallest;
}

vector<int> get_second_largest_smallest(vector<int> &arr, int n) {
    int secLargest = get_2nd_largest(arr, n);
    int secSmallest = get_2nd_smallest(arr, n);
    return {secLargest, secSmallest};
}

int remove_duplicate_get_unique_count(vector<int> &arr, int n) {
    /**
     * Brute-force approach would be to use a 'Set' data structure to push each element
     * and then replace those unique set elements in the original array and return set size.
     * 
     * In Optimal approach, we'll use "two-pointer" to track the recent unique ele and an iterator.
     */
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != arr[k]) {
            arr[k+1] = arr[i];
            k++;
        }
    }

    return k+1;
}

int main() {
    /* Second Largest and Smallest in array */
    vector<int> arr = {1,2,4,7,7,5};

    vector<int> result = get_second_largest_smallest(arr, arr.size());
    
    cout << "Second Largest: " << result[0] << endl;
    cout << "Second Smallest: " << result[1] << endl;
    
    cout << endl;

    /* Remove duplicates in sorted array (in-place), and return # of unique elements */
    vector<int> arr2 = {1,1,2,2,2,3,3};
    int result2 = remove_duplicate_get_unique_count(arr2, arr2.size());
    cout << "# of Unique elements: " << result2 << endl;

    return 0;
}