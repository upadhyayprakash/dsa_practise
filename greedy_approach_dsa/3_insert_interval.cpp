// YouTube: https://youtu.be/xxRE-46OCC8?si=PEseRxPtRt-pEPZQ

#include <iostream>
#include <set>
using namespace std;

vector<pair<int, int>> insert_interval_brute_force(vector<pair<int, int>> intervals, pair<int, int> newInterval) {
    vector<pair<int,int>> ans;
    int i = 0;
    int n = intervals.size();
    
    // initial non-overlapping
    while(i < n && intervals[i].second < newInterval.first) {
        ans.push_back(intervals[i]);
        i++;
    }

    // overlapping sections
    while(i < n && intervals[i].first <= newInterval.second) {
        newInterval.first = min(newInterval.first, intervals[i].first);
        newInterval.second = max(newInterval.second, intervals[i].second);
        i++;
    }
    ans.push_back(newInterval);

    // last non-overlapping
    while(i < n && intervals[i].first > newInterval.second) {
        ans.push_back(intervals[i]);
        i++;
    }


    return ans;
}

int main() {
    vector<pair<int, int>> intervals = {{1,2}, {3,4}, {7,7}, {8,10}, {12,16}};
    pair<int, int> newInterval = {5,8};

    cout << "Given intervals:\n";
    for(auto i: intervals) {
        cout << i.first << ", " << i.second << endl;
    }

    vector<pair<int, int>> ans = insert_interval_brute_force(intervals, newInterval);

    cout << "Updated intervals:\n";
    for(auto i: ans) {
        cout << i.first << ", " << i.second << endl;
    }

    return 0;
}