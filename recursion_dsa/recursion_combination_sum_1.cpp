/*
Recursion: Combination Sum-1
Array has no 0 or negative elements (or it'll create infinite combinations)

*/
#include <iostream>
#include <vector>
using namespace std;

void printArguments(int idx, vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &ans) {
    cout << "\nArguments ====="<< endl;
    cout << "idx=" << idx;
    cout << ", target=" << target;
    cout << ", ds=";
    if(!ds.size()) cout << "{}";
    for(auto i: ds) {
        cout << i << " ";
    }
}

void combination_sum_1(
    int idx,
    vector<int> &arr,
    int n,
    int target,
    vector<int> &ds,
    vector<vector<int>> &ans
) {
    printArguments(idx, arr, target, ds, ans);
    // Base/Exit condition
    if(idx == n) {
        if(target == 0) {;
            ans.push_back(ds);
        }
        return;
    }

    // Recursive Call
    if(arr[idx] <= target) {
        ds.push_back(arr[idx]);
        combination_sum_1(idx, arr, n, target-arr[idx], ds, ans);
        ds.pop_back();
    }

    
    combination_sum_1(idx+1, arr, n, target, ds, ans);
}

int main() {
    vector<int> arr = {2,100,7,6,9,13};
    // vector<int> arr = {2,3,6,7};
    int size = arr.size();
    int target = 13;
    vector<int> ds;
    vector<vector<int>> ans;

    // Input Array
    cout << "Input Array: ";
    for(auto i: arr) {
        cout << i << " ";
    }

    cout << "\nTarget: " << target << endl;

    combination_sum_1(0, arr, size, target, ds, ans);
    
    cout << "\n\nValid Combinations: ";
    for(int i = 0; i< ans.size(); i++) {
        cout << endl << (i+1) << "-> ";
        for(auto j: ans[i]) {
            cout << j << " ";
        }
    }
    return 0;
}