/**
 * Replace array elements by its rank.
 */

#include <iostream>
#include <set>
#include <queue>
using namespace std;

/**
 * Approach: Brute-force
 * 1. For every element in array, check how many other elements are smaller than 'ele'
 * 2. The rank of 'ele' = 1 + (number of unique elements smaller than 'ele')
 * TC: O(N^2), for nested loops
 * SC: O(N), for storing set elements
 */
vector<int> replace_ele_by_rank_brute(vector<int> &arr) {
    vector<int> result;
    for(int i = 0; i < arr.size(); i++) {
        set<int> s;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] < arr[i])
                s.insert(arr[j]);
        }
        result.push_back(s.size() + 1);
    }
    return result;
}

struct compare {
    public:
        bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
            return p1.first < p2.first;
        }
};

/**
 * Approach: Optimal
 * 1. Create another array arr_1 with <value,index> pair.
 * 2. Sort this new array by value.
 * 3. Traverse through this and update the original array rank by using a 'rank' counter.
 * 
 * TC: O(NLogN), for sorting
 * SC: O(2N), for pair vector
 */
vector<int> replace_ele_by_rank_optimal(vector<int> &arr) {
    if(arr.empty()) return {};
    vector<pair<int, int>> arr_1;
    
    // Step-1: Create a pair vector with <value,index> from 'arr'
    for(int i = 0; i < arr.size(); i++)
        arr_1.push_back({arr[i], i});
    
    // Step-2: Sort the pair vector
    sort(arr_1.begin(), arr_1.end(), compare()); // TC: O(NLogN)

    // Step-3: Calculate 'rank' from sorted array arr_1 and update 'arr'
    int rank = 1;
    for(int i = 0; i < arr_1.size() - 1; i++) {
        arr[arr_1[i].second] = rank;
        if(arr_1[i] != arr_1[i+1])
            rank++;
    }
    // Step-4: Handle the last element
    arr[arr_1.back().second] = rank;
    
    return arr;
}

int main() {
    vector<int> arr = {20,15,26,2,98,6};
    cout << "Elements by Rank:(brute)\n";
    vector<int> result = replace_ele_by_rank_brute(arr);
    for(auto i: result)
        cout << i << " ";

    cout << "\nElements by Rank:(optimal)\n";
    vector<int> result2 = replace_ele_by_rank_optimal(arr);
    for(auto i: result2)
        cout << i << " ";
    return 0;
}