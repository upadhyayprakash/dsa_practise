/**
 * Given list of 'distinct' integers and a 'target'. Return unique combinations of integers
 * that sum up to the 'target'. An integer can be used multiple times.
 * 
 * YouTube(Striver's): https://youtu.be/OyZFFqQtu98?si=ld1uqHszvj3vsVtC
 * Pattern: recursion, combination_sum
 */

#include <iostream>
using namespace std;

void combination_sum(int i, int target, vector<int> &arr, int n, vector<int> &ds, vector<vector<int>> &ans) {
    // Base Condition
    if(i == n) { // all elements searched
        if(target == 0) {
            ans.push_back(ds);
        }
        return;
    }

    // Recursive Call: pick
    if(arr[i] <= target) { // can be used for target
        ds.push_back(arr[i]);
        combination_sum(i, target-arr[i], arr, n, ds, ans); // ele can be used multiple times, hence 'i'
        ds.pop_back();
    }

    // Recursive Call: no-pick
    combination_sum(i+1, target, arr, n, ds, ans); // next element, hence 'i+1'
}

int main() {
    vector<int> arr = {2,3,6,7};
    int n = arr.size();
    int target = 13;
    
    cout << "Input Array:\n";
    for(auto i: arr) {
        cout << i << " ";
    }

    cout << "\nTarget:\n" << target << endl;

    vector<vector<int>> ans; // store final sequence of unique combinations
    vector<int> ds; // store each combination of integers
    
    combination_sum(0, target, arr, n, ds, ans);

    cout << "Unique combinations:\n";
    for(auto it: ans) {
        for(auto i: it) {
            cout << i << ", ";
        }
        cout << endl;
    }
    return 0;
}