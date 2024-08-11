/**
 * Alternatively merge characters of 2 strings
 * LeetCode: https://leetcode.com/problems/merge-strings-alternately
 */

#include <iostream>
using namespace std;

string merge_alternatively(string word1, string word2) { // TC: O(N), SC: O(1)
    string result = "";
    int i = 0;
    while(i < word1.length() || i < word2.length()) {
        if(i < word1.length()) result += word1[i];
        if(i < word2.length()) result += word2[i];
        i++;
    }
    return result;
}

int main() {
    string word1 = "abc";
    string word2 = "pqr";
    string result = merge_alternatively(word1, word2);
    cout << "Merged result:\n" << result;
    return 0;
}