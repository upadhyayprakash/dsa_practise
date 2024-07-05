#include <iostream>
using namespace std;


/**
 * Merge Logic for merge_sort
 * Approach:
 * - store two virtual sub-arrays into 'temp' array by comparing them
 * one-by-one and then push left-over elements from those arrays into temp array.
 * - Finally, amend the original array using the sorted 'temp' array and return.
 */

void merge(int arr[], int start, int end, int mid) {
    /*
    Dry Run: 
        Input: [1,3,0,100,12,-4,9]
        
        merge(arr, 0, 1, 0);
    */
    int temp[start+end+1]; // temp array of same size as 'arr'.
    int i = 0;
    
    int left = start; // left sub-array pointer
    int right = mid+1; // right sub-array pointer
    while(left <= mid && right <=end) {
        if(arr[left] <= arr[right]) {
            temp[i++] = arr[left];
            left++; // increment left pointer
        } else {
            temp[i++] = arr[right];
            right++; // increment right pointer
        }
    }

    // Push remaining elements from left sub-array
    while(left <= mid) {
        temp[i++] = arr[left];
        left++;  // don't forget to increment here
    }

    // Push remaining elements from right sub-array
    while(right <= end) {
        temp[i++] = arr[right];
        right++; // don't forget to increment here
    }

    // Copy the sorted 'temp' array onto original array 'arr'
    for(int j = start; j <= end; j++) {
        arr[j] = temp[j - start]; // "j-start" will ensure temp index is starting from 0.
    }
    return;
}

/**
 * Approach: Divide at 'mid' until single element in each side and then 'Merge'.
 */
void merge_sort(int arr[], int start, int end) { // Time Complexity: O(n*logn). Space Complexity: O(n)
    // Base condition: when only one element in 
    if(start == end)
        return;

    // Task: Split the array into halves
    int mid = (start + end) / 2;

    // Recursive Call
    merge_sort(arr, start, mid); // left sub-array
    merge_sort(arr, mid+1, end); // right sub-array

    merge(arr, start, end, mid);

    return;

    /*
    Dry Run:
    Input: [1,3,0,100,12,-4,9]
    Recursive Calls:
    1.  merge_sort([1,3,0,100,12,-4,9], 0, 6)
            merge_sort([1,3,0,100], 0, 3)
                merge_sort([1,3], 0, 1) -> 'merge' happens here
                    merge_sort([1], 0, 0) -> returns
                    merge_sort([3], 1, 1) -> returns
                merge_sort([0,100], 2, 3)
                    merge_sort([0], 2, 2)
                    merge_sort([100], 3, 3)
            merge_sort([12,-4,9], 4, 6)


     */
}

int main() {
    // Take Input array
    int size;
    cin >> size;
    int arr[size];
    cout << "Input array:" << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Call Sorting Algo
    merge_sort(arr, 0, size-1);

    // Print sorted array
    cout << "\nSorted Array:" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}