// YouTube: https://youtu.be/2JzRBPFYbKE?si=bGCYtj2YaOiTNinM
#include <iostream>
#include <vector>
using namespace std;

bool sortBySecond(pair<int, int> &a, pair<int, int> &b) {
    return (a.second < b.second);
}

vector<pair<int, int>> merge_intervals(vector<pair<int, int>> &arr) {
    /*
        Approach:
        1. Take a pair variable as a reference and match it with next one to check if it overlaps.
        2. If it doesn't then add that pair reference variable to answer and increment 'i'.
        3. If it overlaps, then keep merging the 'pair' and the next intervals together and
            at the end, push the merged pair to 'ans'
    */
   
    // TODO
    return {{}};
}

int main() {
    vector<pair<int, int>> arr = {{1,3}, {2,6}, {8,10}, {8,9}, {9,11},{15,18}, {2,4}, {16,17}};

    cout << "Given intervals:\n";
    for(auto i: arr) {
        cout << i.first << ", " << i.second << endl;
    }

    cout << "Sorted intervals (by first):\n";
    sort(arr.begin(), arr.end());
    for(auto i: arr) {
        cout << i.first << ", " << i.second << endl;
    }

    // cout << "Sorted intervals (by second):\n";
    // sort(arr.begin(), arr.end(), sortBySecond);
    // for(auto i: arr) {
    //     cout << i.first << ", " << i.second << endl;
    // }

    cout << "Merged intervals:\n";
    vector<pair<int, int>> ans = merge_intervals(arr);
    for(auto i: ans) {
        cout << i.first << ", " << i.second << endl;
    }

    return 0;
}