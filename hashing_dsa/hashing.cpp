#include <map>
#include <iostream>
using namespace std;

void basic_hash_counter_int() {
    // Take size of array
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    
    cout << endl;

    // Creating hash array
    int hash[5] = {0};
    for(int i = 0; i < size; i++) {
        hash[arr[i]] += 1;
    }

    // Take size of queries
    int qSize;
    cin >> qSize;
    
    while(qSize--) {
        int qNum;
        cin >> qNum;
        cout << "Count of " << qNum << ": " << hash[qNum] << endl;
    }
}

void basic_hash_counter_char() {
    // Input string sequence
    string str = "abcdabcaa"; // all small-case alphabets ONLY

    // Hash into a frequency array
    int freqArr[26] = {0};
    for(int i = 0; i < str.length(); i++) {
        freqArr[str[i] - 'a'] += 1;
    }

    // Print freqArr
    cout << endl << "Frequency Array:" << endl;
    for(auto i: freqArr) {
        cout << i << " ";
    }

    cout << endl;

    // query array
    char qArr[] = {'c', 'a', 'd', 'b'};
    int qSize = sizeof(qArr) / sizeof(*qArr);
    for(int i = 0; i < qSize; i++) {
        cout << "Count of " << qArr[i] << ": " << freqArr[qArr[i] - 'a'] << endl;
    }
}

void map_counter_int() { // For integers
    // Take size of array
    int size;
    cin >> size;
    int arr[size];
    map<int, int> freqArr; // frequency array declaration
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        freqArr[arr[i]]++;
        cout << arr[i] << " "; // display input array elements
    }
    
    cout << endl;

    // Print the frequency Map
    cout << "Map: " << endl;
    for(auto i: freqArr) {
        cout << i.first << "->" << i.second << " " << endl;
    }
    
    cout << endl;

    // Take size of queries
    int qSize;
    cin >> qSize;
    
    while(qSize--) {
        int qNum;
        cin >> qNum;
        cout << "Count of " << qNum << ": " << freqArr[qNum] << endl;
    }

}

int main() {
    // basic_hash_counter_int();
    basic_hash_counter_char();
    // map_counter_int();
    return 0;
}