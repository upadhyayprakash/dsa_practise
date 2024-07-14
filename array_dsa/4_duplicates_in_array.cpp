#include <iostream>
#include <unordered_set>
using namespace std;

// brute-force
string check_duplicate_brute_force(vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i+1; j < arr.size(); j++) {
            if(arr[i] == arr[j]) {
                return "true";
            }
        }
    }
    return "false";
}

// better: sort the array and check for adjacent elements for duplicates.
string check_duplicate_better(vector<int> &arr) {
    // TODO: sort the array and loop through elements to check duplicates in adjacent elements
    return "true";
}

/*
    Optimal:
        Use 'unordered_set' to store visited elements, check next elements
        if it exists already.
*/
string check_duplicate_optimal(vector<int> &arr) {
    unordered_set<int> us;
    for(int i = 0; i < arr.size(); i++) {
        us.insert(arr[i]);
    }
    if(us.size() < arr.size())
        return "true";
        
    return "false";
}

int main() {
    vector<int> arr = {1,2,3,1};
    cout << "Contains duplicates? (brute-force)\n" << check_duplicate_brute_force(arr) << endl;
    cout << "Contains duplicates? (optimal)\n" << check_duplicate_optimal(arr);
    return 0;
}