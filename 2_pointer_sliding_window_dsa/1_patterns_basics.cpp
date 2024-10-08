#include <iostream>
#include <vector>
using namespace std;

vector<int> largest_sum_with_k_elements(vector<int> &arr, int n, int k) {
    /*
    Input:
    arr -> {-1,2,3,3,4,5,-1}
    k -> 3 (3 consecutive elements window)
    */
    
    if(k > n)
        return {};

    int maxSum = arr[0];
    vector<int> result;
    
    for(int i = 1; i < k; i++) {
        maxSum += arr[i];
    }
    
    int sum = maxSum;
    int l = 0;
    int r = k - 1;
    int lMax = l;
    int rMax = r;
    while(r < n - 1) {
        sum += arr[++r];
        sum -= arr[l++];
        if(sum > maxSum) {
            maxSum = sum;
            lMax = l;
            rMax = r;
        }
    }

    for(int i = lMax; i <= rMax; i++) {
        result.push_back(arr[i]);
    }
    return result;
}

int get_max_sub_array_length_with_sum_less_equal_brute_force(vector<int> &arr, int n, int k) {
    int maxLength = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            if(sum <= k)
                maxLength = max(maxLength, j-i+1);
            else if(sum >k) {
                break;
            }
        }
    }
    return maxLength;
}

int get_max_sub_array_length_with_sum_less_equal_2_pointer(vector<int> &arr, int n, int k) {
    /*
    Input:
        arr -> {2,5,1,7,10}
        k -> 11
    */
    
    int l,r;
    l = r = 0;
    int maxLength = 0;
    int sum = arr[l];
    while(r < n) {
        if(sum <= k) {
            maxLength = max(maxLength, r-l+1);
            r++;
            sum += arr[r];
        } else {
            /* This while loop can be skipped if all we want is the "length of sub-array" and not the
            sub-array itself. To acheive this, 'l' can be shifted only once, i.e.till current
            maxLength value. */
            while (sum > k) {
                // while loop intuition is to keep subtracting until 'sum' is within limit. when asked for sub-array itself and not just 'length'.
                sum -= arr[l];
                l++;
            }
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {-1,2,3,3,4,5,-1};
    cout << "Original Array:" << endl;
    for(auto i: arr) {
        cout << i << " ";
    }


    cout << "\nBiggest sum range of k elements:" << endl;
    vector<int> result = largest_sum_with_k_elements(arr, arr.size(), 3);
    if(!result.size()) cout << "<empty>" << endl;
    for(auto i: result) {
        cout << i << " ";
    }

    /* Pattern-1: Sub-array generation template with a condition and early break */
    vector<int> arr2 = {2,5,1,1,10};
    int k = 11;
    int result2 = get_max_sub_array_length_with_sum_less_equal_brute_force(arr2, arr2.size(), k);
    cout << "\nMax length (consecutive sub-array) with sum <= " << k << " is (brute-force):";
    cout << endl << result2 << endl;

    /* Pattern-2: Using 2-Pointer and window expand/shrink method to get the max window length */
    int result3 = get_max_sub_array_length_with_sum_less_equal_2_pointer(arr2, arr2.size(), k);
    cout << "\nMax length (consecutive sub-array) with sum <= " << k << " is (2-pointer):";
    cout << endl << result3 << endl;

    /**
     * Pattern-3: Number of sub-arrays where <condition> (eg. 'sum' of elements = k)
     * For this, by using pattern-2, we'll find,
     * 1. # of arrays with sum <= k
     * 2. # of arrays with sum <= k-1
     * 
     * And to get the answer = we subtract # from 1 - # from 2
     */

    /**
     * Pattern-4: Shortest/Minimum sub-array with <condition>.
     * For this, we take an initial big window that satisfies the <condition> and then
     * shrink it till condition is still valid.
     */

    return 0;
}