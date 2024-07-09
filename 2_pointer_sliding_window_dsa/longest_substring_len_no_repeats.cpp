#include <iostream>
using namespace std;

int longest_substring_len_no_repeat_chars(string str) {
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

int main() {
    string str = "cadbazabcad";
    int maxLength = longest_substring_len_no_repeat_chars(str);
    cout << "Given string: " << str << endl;
    cout << "Longest substring length (no char repeat):\n" << maxLength << endl;
    return 0;
}