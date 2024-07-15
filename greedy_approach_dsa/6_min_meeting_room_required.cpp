#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_meeting_rooms_required(int start[], int end[], int n){
    sort(start, start + n);
    sort(end, end + n);

    cout << "Sorted 'start' and 'end' lists:\n";
    for(int i = 0; i < n; i++) {
        cout << start[i] << " | " << end[i] << endl;
    }

    int roomActive = 0, maxRoom = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if(start[i] < end[j]) {
            roomActive++;
            i++;
        } else {
            roomActive--;
            j++;
        }
        maxRoom = max(maxRoom, roomActive);
    }

    return maxRoom;
    
}

int main() {
    int start[] = {1,3,5,6,7,10};
    int end[] = {2,4,8,9,10,11};
    int size = sizeof(start)/sizeof(*start);
    
    cout << "Meeting List:" << endl;
    for(int i = 0; i < size; i++) {
        cout << start[i] << ", " << end[i] << endl;
    }

    cout << "Required meeting rooms:\n" << min_meeting_rooms_required(start, end, size);
    return 0;
}