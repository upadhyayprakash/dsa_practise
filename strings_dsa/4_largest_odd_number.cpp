/**
 * Given a 'num' string. Find the largest odd number in that numeric string.
 * LeetCode: https://leetcode.com/problems/largest-odd-number-in-string/description/
 */

#include <iostream>
using namespace std;

string largest_odd_substring(string num) {
    for(int i = num.size() - 1; i >= 0; i--) {
        if(num[i] % 2 != 0) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    string num = "35438";
    cout << "Largest Odd substring:\n" << largest_odd_substring(num);
    return 0;
}