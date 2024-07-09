#include <iostream>
#include <unordered_map>
using namespace std;

int longest_substring_len_no_repeat_chars_brute_force(string str) { // Time Complexity: O(n^2), Space Complexity: O(256)
    /*
    Input:
        str -> "cadbzabcd"
    */
    int maxLen = 0;
    for(int i = 0; i < str.length(); i++) {
        int hash[256] = {0};
        for(int j = i; j < str.length(); j++) {
            if(hash[str[j]] == 1) {
                break;
            } else {
                maxLen = max(maxLen, j-i+1);
                hash[str[j]] = 1;
            }
        }
    }
    return maxLen;
}

int longest_substring_len_no_repeat_chars_optimal(string str) { // Time Complexity: O(n), Space Complexity: O(256)
    /*
    Input:
        str -> "cadbzabcd"
    */
    int maxLen = 0;
    int l = 0;
    int r = 0;
    int hash[256];
    fill_n(hash, 256, -1);
    while(r < str.length()) {
        if(hash[str[r]] != -1 && hash[str[r]] >= l) { // already seen and in the range "l -> r"
            l = hash[str[r]] + 1;
            hash[str[r]] = r;
        } else { // new encounter
            hash[str[r]] = r;
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    
    return maxLen;
}

int main() {
    string str = "cadbazbcad";
    cout << "Given string: " << str << endl;

    // Brute-force Approach: find all substring using loops and use hash[256] to know seen characters.
    int maxLength = longest_substring_len_no_repeat_chars_brute_force(str);
    cout << "(Brute-Force) Longest substring length (no char repeat):\n" << maxLength << endl;
    
    /*
    Optimal Approach: We use 2-pointer, and a 'HashMap' (unordered_map in C++) to track seen chars with their index.
    */
    int maxLength2 = longest_substring_len_no_repeat_chars_optimal(str);
    cout << "(Optimal) Longest substring length (no char repeat):\n" << maxLength2 << endl;
    return 0;
}