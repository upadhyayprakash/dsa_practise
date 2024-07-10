// YouTube: https://youtu.be/xtqN4qlgr8s?si=5kXa_hzA9L-gYRYM
#include <iostream>
#include <unordered_map>
using namespace std;

int num_of_substr_with_all_given_chars_brute_force(string str) {
    /* 
        Input:
            str -> b b a c b a
        Approach:
        1. We'll find all substring and maintain a hash array of 3 length to track
        if the char has been seen.
        2. If all the chars are seen in any substring, we'll increment the count.
        3. Time Complexity: O(n^2). Space Complexity: O(1)
    */
    int cnt = 0;

    for(int i = 0; i < str.length(); i++) {
        int hash[3] = {0};
        for(int j = i; j < str.length(); j++) {
            hash[str[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3)
                cnt = cnt + 1;
        }
    }
    return cnt;
}

int num_of_substr_with_all_given_chars_better(string str) {
    /* 
        Input:
            str -> b b a c b a
        Better Approach:
        1. We could reduce the inner loops traversals once we get our "first" valid substring and simply
        add remaining characters count to 'cnt' as indication of future substrings.
        2. Time Complexity: O(n^2), Space Complexity: O(1)
    */
    int cnt = 0;

    for(int i = 0; i < str.length(); i++) {
        int hash[3] = {0};
        for(int j = i; j < str.length(); j++) {
            hash[str[j] - 'a'] = 1;
            if(hash[0] + hash[1] + hash[2] == 3) {
                cnt = cnt + (str.length() - j);
                break;
            }
        }
    }
    return cnt;
}

int num_of_substr_with_all_given_chars_optimal(string str) {
    /* 
        Input:
            str -> b b a c b a
        Optimal Approach:
        1. We'll try to find the smallest valid substring that ends at third character.
        2. In above case, 'b a c'.
        3. We'll then add all previous chars appearance as a valid substring count.
        4. In above case, we see one 'b' appears before 'b a c', hence the total count = 2.
        5. To keep track of the oldest(smallest 'i' among three chars) character's last seen
        position, we'll maintain an array[3] with char's last seen position.
        6. Time Complexity: O(n), Space Complexity: O(1)
    */
    int cnt = 0;
    int lastSeen[3] = {-1, -1, -1}; // '0' is a valid index, hence assign -1.
    for(int i = 0; i < str.length(); i++) {
        lastSeen[str[i] - 'a'] = i; // update char's current position

        if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
            cnt = cnt + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
        }
    }
    
    return cnt;
}

int main() {
    string str = "bbacba";
    cout << "Given string: " << str << endl;
    cout << "\nNum of substring with all 3 chars:\n(brute-force)" << endl;
    cout << num_of_substr_with_all_given_chars_brute_force(str) << endl;

    cout << "\nNum of substring with all 3 chars:\n(better)" << endl;
    cout << num_of_substr_with_all_given_chars_better(str);

    cout << "\nNum of substring with all 3 chars:\n(optimal)" << endl;
    cout << num_of_substr_with_all_given_chars_optimal(str);
    return 0;
}