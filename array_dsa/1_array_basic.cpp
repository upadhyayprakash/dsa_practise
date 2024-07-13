#include <iostream>
#include <vector>
#include <algorithm>
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

/**
 * Rotate an array left by 'd' positions
 * 
 * 1. Worst Approach: O(d x N)
 * 
 * 
 * 2. Brute-force approach would be to store 1st 'd' elements in temporary array and  move others to left
 * and then push temp array content to end of original array.
 * 
 * 3. In optimal approach, we'd reverse the two sub-array split by 'd' position and then reverse the entire
 * array to get the result.
 */
void rotate_array_by_d_spaces_optimal(int arr[], int n, int d) { // Time Complexity: O(d x n)
    /*
    Input:
    Eg. [1,2,3,4,5,6,7];
    d = 3

    Approach:
    Reverse: arr(0, d-1) -> [3,2,1]
    Reverse: arr(d, n-1) -> [7,6,5,4]
    Combine: [3,2,1,7,6,5,4]
    Reverse: [4,5,6,7,1,2,3]
    */

   reverse(arr, arr+d);
   reverse(arr+d, arr+n);
   reverse(arr, arr+n);
}

/**
 * Move all zero elements to the end of array.
 * 
 * Brute-force approach is to create a temp array and store all the non-zero
 * elements in it, and then insert that array at the beginning of 'arr'. Later,
 * make all the remaining elements as '0'. It has Space Complexity: O(N)
 * 
 * Optimal Approach:
 * - We'll use 2-pointer to swap the non-zero occurrences with zeroes in the array.
 * - Constant Space Complexity: O(1)
 */

void move_zeroes_to_end_optimal(vector<int> &arr, int n) {
    // Find the 1st zero element and track it.
    int zeroEleIdx = -1;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            zeroEleIdx = i;
            break;
        }
    }

    // Traverse further elements and swap zero with them
    for(int i = zeroEleIdx + 1; i < n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[zeroEleIdx]);
            zeroEleIdx++;
        }
    }
}


/**
 * Get UNION of two 'sorted' arrays
 * 
 * Brute-force approach would be to use a 'Set' data structure to store every element from
 * given two arrays, and then copy the set to another "result<int>" vector.
 * 
 * Optimal: Use two pointer
 */
vector<int> union_of_2_arrays(vector<int> arr1, int n1, vector<int> arr2, int n2) {
    /*
    Input:
        arr1: [1,1,2,3,4,5]
        arr2: [2,3,4,4,5,6]
    */

    int i, j;
    i = j = 0;
    vector<int> result;

    while(i < n1 && j < n2) {
        if(arr1[i] <= arr2[j]) {
            if(result.size() == 0 || result.back() != arr1[i])
                result.push_back(arr1[i]); // result: [1]
            i++;
        }
        else {
            if(result.size() == 0 || result.back() != arr2[j])
                result.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n1) {
        if(result.size() == 0 || result.back() != arr1[i])
            result.push_back(arr1[i]);
        i++;
    }

    while(j < n2) {
        if(result.size() == 0 ||result.back() != arr2[j])
            result.push_back(arr2[j]);
        j++;
    }

    return result;
}


/**
 * Intersection of two 'sorted' arrays. Intersection result array can contain duplicate value if it's common
 * betweeen two arrays
 */
vector<int> intersection_of_2_arrays(vector<int> a, int n1, vector<int> b, int n2) {
    /*
    Approach:
    Input:
        arr1: {1,2,2,3,3,4,5,6};
        arr2: {2,3,3,5,6,6,7};
    */

    int i = 0, j = 0;
    vector<int> result;
    while(i < n1 && j < n2) {
        if(a[i] == b[j]) {
            result.push_back(a[i]);
            i++;
            j++;
        } else if(a[i] <= b[j]) {
            i++;
        } else {
            j++;
        }
    }

    return result;
}


int main() {
    /* Second Largest and Smallest in array */
    // vector<int> arr = {1,2,4,7,7,5};

    // vector<int> result = get_second_largest_smallest(arr, arr.size());
    
    // cout << "Second Largest: " << result[0] << endl;
    // cout << "Second Smallest: " << result[1] << endl;
    
    // cout << endl;

    /* Remove duplicates in sorted array (in-place), and return # of unique elements */
    // vector<int> arr2 = {1,1,2,2,2,3,3};
    // int result2 = remove_duplicate_get_unique_count(arr2, arr2.size());
    // cout << "# of Unique elements: " << result2 << endl;

    /* Rotate array by 'd' positions */
    // int arr3[] = {1,2,3,4,5,6,7};
    // int size3 = (sizeof(arr3)/sizeof(*arr3));
    // int d = 3;
    // int rotations = d % size3;
    // cout << "\nOriginal array:" << endl;
    // for(auto i: arr3) {
    //     cout << i << " ";
    // }

    // rotate_array_by_d_spaces_optimal(arr3, size3, rotations);

    // cout << "\nRotated array by " << rotations << " spaces:" << endl;
    // for(auto i: arr3) {
    //     cout << i << " ";
    // }

    /* Move all zeros to the end */
    // vector<int> arr4 = {0,1,0,4,0,0,7,13,0,5};
    // cout << "Original Array:" << endl;
    // for(auto i: arr4) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // move_zeroes_to_end_optimal(arr4, arr4.size());
    // cout << "Processed Array:" << endl;
    // for(auto i: arr4) {
    //     cout << i << " ";
    // }


    /* Return UNION of two "sorted" array. Unions contains unique elements from both arrays. */
    // vector<int> arr5_1 = {1,1,2,3,4,5};
    // vector<int> arr5_2 = {2,3,4,4,5,6};

    // cout << "Union of two arrays: " << endl;

    // vector<int> result5 = union_of_2_arrays(arr5_1, arr5_1.size(), arr5_2, arr5_2.size());

    // for(auto i: result5) {
    //     cout << i << " ";
    // }

    /*
    Return INTERSECTION of two "sorted" array. Intersection contains common elements from both arrays
    AND can have REPEATeD values.
    */
    vector<int> arr6_1 = {1,2,2,3,3,4,5,6};
    vector<int> arr6_2 = {2,3,3,5,6,6,7};

    cout << "Intersection of two arrays: " << endl;

    vector<int> result6 = intersection_of_2_arrays(arr6_1, arr6_1.size(), arr6_2, arr6_2.size());

    for(auto i: result6) {
        cout << i << " ";
    }

    cout << "\n\nProgram Finished!";

    return 0;
}