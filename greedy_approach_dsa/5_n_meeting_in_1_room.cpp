#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sortByMeetingEndTime(vector<int> a, vector<int> b) {
    if(a[1] < b[1])
        return true;
    else if(a[1] > b[2])
        return false;
    else if(a[2] < b[2])
        return true;
}

void max_meetings_1_room(int start[], int end[], int n){
    vector<vector<int>> meetings;
    for(int i = 0; i < n; i++) {
        meetings.push_back({start[i], end[i], i+1});
    }

    cout << "Meeting List:" << endl;
    for(auto m: meetings) {
        cout << m[0] << ", " << m[1] << " -> " << m[2] << endl;
    }

    stable_sort(meetings.begin(), meetings.end(), sortByMeetingEndTime);
    cout << "\nSorted by \"end-time\":" << endl;
    for(auto m: meetings) {
        cout << m[0] << ", " << m[1] << " -> " << m[2] << endl;
    }
    
    vector<int> ans;

    ans.push_back(meetings[0][2]); // push first meeting's postion from 'sorted' meetings

    int endTime = meetings[0][1]; // assign "end-time" of 1st meeting as reference

    for(int i = 1; i < n; i++) {
        if(meetings[i][0] > endTime) { // if meetings 'start' is more than last meetings 'end' time
            ans.push_back(meetings[i][2]);
            endTime = meetings[i][1]; // update last meeting end time with current meetings end time
        }
    }
    
    cout << "\nOrder for max meetings:" << endl;
    for(auto i: ans) {
        cout << i << " ";
    }
}

int main() {
    int start[] = {1,0,3,8,5,8};
    int end[] = {2,6,4,9,7,9};
    int size = sizeof(start)/sizeof(*start);
    max_meetings_1_room(start, end, size);
    return 0;
}