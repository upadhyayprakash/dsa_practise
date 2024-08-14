/**
 * Given a list of integers (may contain duplicates) and a 'target' integer. Find all
 * "unique" combinations of integers that sum up to the 'target'. Use every integers only
 * "once".
 * 
 * YouTube(Striver's): https://youtu.be/G1fRTGRxXU8?si=RrPxdTqO9sSjc_y9
 * Pattern: recursion, combination_sum
 */

#include <iostream>
#include <set>
using namespace std;

void combination_sum_brute_force(int i, int target, vector<int> &arr, int n, vector<int> &ds, set<vector<int>> &ans) {
    // Base Condition
    if(i == n) {
        if(target == 0) {
            sort(ds.begin(), ds.end());
            ans.insert(ds);
        }
        return;
    }

    // Recursive Calls
    if(arr[i] <= target) {
        ds.push_back(arr[i]);
        combination_sum_brute_force(i+1, target-arr[i], arr, n, ds, ans);
        ds.pop_back();
    }

    combination_sum_brute_force(i+1, target, arr, n, ds, ans);
}

void combination_sum_optimal(int ind, int target, vector<int> &arr, int n, vector<int> &ds, vector<vector<int>> &ans) {
    // Base Condition: when target is '0', ds already has combination, add to 'ans'
    if(target == 0) {
        ans.push_back(ds);
        return;
    }
    
    // Loop through all indices for ith position
    for(int i = ind; i < n; i++) {
        // check if same value as last pick, skip this iteration
        if(i > ind && arr[i] == arr[i-1]) continue;

        // check if arr[i] > target, break (because anything later is greater as array is sorted)
        if(arr[i] > target) break;

        ds.push_back(arr[i]);
        combination_sum_optimal(i+1, target - arr[i], arr, n, ds, ans);
        ds.pop_back();

    }
}

int main() {
    vector<int> arr = {10,1,2,7,6,1,5};
    int n = arr.size();
    int target = 8;

    cout << "Input Array:\n";
    for(auto i: arr) {
        cout << i << " ";
    }

    cout << "\nTarget:\n" << target << endl;

    set<vector<int>> ans;
    vector<int> ds;

    // Brute-force
    combination_sum_brute_force(0, target, arr, n, ds, ans);

    cout << "Unique combinations(brute):\n";
    for(auto it: ans) {
        for(auto i: it) {
            cout << i << ", ";
        }
        cout << endl;
    }

    // Optimal
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans2;
    vector<int> ds2;
    combination_sum_optimal(0, target, arr, n, ds2, ans2);

    cout << "Unique combinations(optimal):\n";
    for(auto it: ans2) {
        for(auto i: it) {
            cout << i << ", ";
        }
        cout << endl;
    }
    
    return 0;
}