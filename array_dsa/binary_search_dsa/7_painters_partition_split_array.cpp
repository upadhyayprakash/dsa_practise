/**
 * 1. Split the array into sub-arrays of consecutive elements to minimize max sum among sub-arrays.
 * 2. Painter's Partition of 'N' boards
 * YouTube (Striver's): https://youtu.be/thUd_WJn6wk?si=u4wDZCvlBgOutxCB
 * Pattern: Binary Search on 'Answers'
 */

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int get_sub_array_count(vector<int> &arr, int mid) {
    int count = 1;
    int sumOfSubArray = 0;
    for(auto i: arr) {
        if(sumOfSubArray + i <= mid)
            sumOfSubArray += i;
        else {
            count++;
            sumOfSubArray = i;
        }
    }
    return count;
}

int get_min_subarary_size(vector<int> &arr, int k) { // TC: O(N * Log2(sumEle - maxEle))
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high) {
        int mid = (low + high) / 2;
        int subArrayCnt = get_sub_array_count(arr, mid);
        if(subArrayCnt <= k) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> arr = {10,20,30,40};
    int k = 2;
    cout << "Minimize max sub-array:\n" << get_min_subarary_size(arr, k);
    return 0;
}