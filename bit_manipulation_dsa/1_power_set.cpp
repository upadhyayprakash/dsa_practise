/**
 * Print all sub-sequence
 * YouTube(Striver's): https://youtu.be/b7AYbpM5YrE?si=EXAb2G4ty0Pg4pkf
 */

#include <iostream>
using namespace std;

/**
 * Approach:
 * 1. We'll use binary bit manipulation to find all combination between 1 and 2^n.
 * 2. "1 << n" means, 1 0 0 in binary. We can use this logic to check if the 2nd bit (indexing from right) is set or not.
 * 3. We'll loop from 0 till (2^n - 1). Eg. for n = 3 ("abc"), we'll loop from 0 to 7.
 * 4. Binary representation looks like, 0 0 0, 0 0 1, 0 1 0, 0 1 1, and so on.
 * 5. We'll use the shift operation with each binary representaion to check if bit is set and
 * use this to select characters from the input 'str'.
 */
void print_all_subsequence(string str) {
    int n = str.length();
    for(int i = 0; i < (1 << n); i++ ) {
        string subStr = "";
        for(int j = 0; j < n; j++) {
            if(i & (1 << j))
                subStr += str[j];
        }
        cout << i << " -> " << subStr << endl;
    }
}

int main() {
    string str = "abc";
    print_all_subsequence(str);
    return 0;
}