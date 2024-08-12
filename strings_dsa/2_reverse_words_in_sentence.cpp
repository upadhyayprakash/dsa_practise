#include <iostream>
using namespace std;

string reverse_words_in_string(string str) {
    int n = str.length();
    string result = "";
    string s = "";
    for(int i = n - 1; i >= 0; i--) {
        if(str[i] == ' ') {
            result += s + ' ';
            s = "";
        }
        else
            s = str[i] + s;
        
    }
    result += s;
    return result;
}

int main() {
    string str = "This is an amazing program";
    cout << "Original:\n" << str << endl;
    
    string result = reverse_words_in_string(str);
    cout << "Reversed:\n" << result;

    return 0;
}