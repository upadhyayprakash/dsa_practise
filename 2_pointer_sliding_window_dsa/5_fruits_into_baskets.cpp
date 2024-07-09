// Problem: https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1
/*
The above problem can be simply stated as, find "length" of max sub-array with at most two types of integers.
Eg. [1,2,1,1,2] is valid, but [2,1,1,3,1] is not, as it has (1,2,3).
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int get_max_length_sub_arr_with_two_types(vector<int> &arr, int n, int k) {
    int l, r;
    l = r = 0;
    int maxLen = 0;
    unordered_map<int, int> numFreq;

    while(r < n) {
        // cout << "while entered" << endl;
        numFreq[arr[r]] = numFreq[arr[r]] + 1;
        if(numFreq.size() <= k) {
            maxLen = max(maxLen, r-l+1);
        } else {
            // move 'l' pointer to most recent occurence of 1st 'set' element
            int ele = arr[l];
            while(numFreq[ele] > 0) {
                numFreq[ele] = numFreq[ele] - 1;
                l++;
            }
            // delete the old ele from map
            unordered_map<int, int>::iterator it = numFreq.find(ele);
            numFreq.erase(it);
        }
        r++;
    }
    return maxLen;
}

int main() {
    vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
    for(auto i: arr) cout << i << " ";
    int k = 2;
    cout << "\nLength of largest sub-array:\n" << get_max_length_sub_arr_with_two_types(arr, arr.size(), k);
    return 0;
}