/**
 * Given a 'text' string (or LinkedList) and 'pattern' string. Check if 'pattern' exists in 'text'.
 */
#include <iostream>
using namespace std;

bool pattern_check_brute(string text, string pattern) { // TC: O(m x n)
    int i = 0, j = 0;
    while(i < text.length()) {
        while(j < pattern.length()) {
            if(text[i+j] == pattern[j])
                j++;
            else
                break;
        }
        if(j == pattern.length()) // match found
            return true;
        j = 0;
        i++;
    }
}

int main() {
    string text = "abxabc";
    string pattern = "abc";
    cout << "Pattern exists?\n" << (pattern_check_brute(text, pattern) ? "YES" : "NO");
    return 0;
}