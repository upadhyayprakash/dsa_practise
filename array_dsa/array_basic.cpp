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

int main() {
    /* Second Largest and Smallest in array */
    vector<int> arr = {1,2,4,7,7,5};

    vector<int> result = get_second_largest_smallest(arr, arr.size());
    
    cout << "Second Largest: " << result[0] << endl;
    cout << "Second Smallest: " << result[1] << endl;
    
    
    return 0;
}