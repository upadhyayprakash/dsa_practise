#include <iostream>
#include <map>
using namespace std;

string two_sum_brute_force(vector<int> &arr, int target) { // Time Complexity: O(n^2)
    for(int i = 0; i < arr.size() - 1; i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] + arr[j] == target && i != j)
                return "YES";
        }
    }
    return "NO";
}

vector<int> two_sum_indices_brute_force(vector<int> &arr, int target) {
    for(int i = 0; i < arr.size() - 1; i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] + arr[j] == target && i != j)
                return {i,j};
        }
    }
    return {-1,-1};
}

string two_sum_better(vector<int> &arr, int target) { // Time Complexity: O(N * LogN), Space Complexity: O(n)
    map<int, int> mp;
    for(int i = 0; i < arr.size(); i++) {
        int ele = arr[i];
        int balance = target - ele;
        if(mp.find(balance) != mp.end()) {
            return "YES";
        }
        mp[ele] = i;
    }
    return "NO";
}

vector<int> two_sum_indices_better(vector<int> &arr, int target) {
    map<int, int> mp;
    for(int i = 0; i < arr.size(); i++) {
        int ele = arr[i];
        int balance = target - ele;
        if(mp.find(balance) != mp.end()) {
            return {mp[balance], i};
        }
        mp[ele] = i;
    }
    return {-1,-1};
}

/* Optimal approach uses 2-pointer approach after 'sorting' the array */
string two_sum_optimal(vector<int> &arr, int target) { // Time Complexity: O(N * LogN)
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int currSum = arr[left] + arr[right];
        if(currSum == target)
            return "YES";
        if(currSum < target)
            left++;
        else
            right--;
    }
    return "NO";
}

vector<int> two_sum_indices_optimal(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int currSum = arr[left] + arr[right];
        if(currSum == target)
            return {left, right};
        if(currSum < target)
            left++;
        else
            right--;
    }
    return {-1,-1};
}

int main() {
    vector<int> arr = {2,6,5,8,11};
    int target = 14;

    // Brute-force: uses 2 loops to find every combination that sums to 'target'
    cout << "Target found? (brute-force):\n" << two_sum_brute_force(arr, target) << endl;
    vector<int> result1 = two_sum_indices_brute_force(arr, target);
    cout << "Target found? (w/ indices) (brute-force):\n";
    for(auto i: result1) {
        cout << i << ",";
    }
    cout << endl;

    // Better: uses hashmap to store elements and their indices
    cout << "Target found? (better):\n" << two_sum_better(arr, target) << endl;
    vector<int> result2 = two_sum_indices_better(arr, target);
    cout << "Target found? (w/ indices) (better):\n";
    for(auto i: result2) {
        cout << i << ",";
    }
    cout << endl;

    // Optimal: sorts the original array. For indices use the "Better" approach only.
    cout << "Target found? (optimal):\n" << two_sum_optimal(arr, target) << endl;
    cout << endl;

    return 0;
}