/**
 * Book allocation among 'm' students to minimize maximum page count.
 * YouTube (Striver's): https://www.youtube.com/watch?v=Z0hwjftStI4
 * Pattern: Binary Search on 'Answers'
 */

#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int count_students(vector<int> &arr, int maxPages) {
    int stdCnt = 1;
    int numOfPages = 0;
    for(auto i: arr) {
        if(numOfPages + i <= maxPages)
            numOfPages += i;
        else {
            stdCnt++;
            numOfPages = i;
        }
    }
    return stdCnt;
}

int get_min_pages_between_students(vector<int> &books, int m) { // TC: O(N * Log2(sumEle - maxEle))
    if(m > books.size()) return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    while(low <= high) {
        int mid = (low + high) / 2;
        int studCnt = count_students(books, mid);
        if(studCnt <= m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> books = {25, 46, 28, 49, 24};
    int m = 4; // number of students
    cout << "Minimize pages between students:\n" << get_min_pages_between_students(books, m);
    return 0;
}