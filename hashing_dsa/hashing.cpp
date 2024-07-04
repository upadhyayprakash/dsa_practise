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
    unordered_map<int, int> freqArr; // frequency array declaration. can use 'map' also.
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

void counter_min_max_freq_ele() {
    // Take array input and hash its elements into a map
    int size;
    cin >> size;
    int arr[size];

    map<int, int> freqArr;

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        freqArr[arr[i]]++;
        cout << arr[i] << " ";
    }

    cout << endl;

    // Print map with hashed elements
    int minEle = freqArr.begin()->first;
    int minValue = freqArr.begin()->second;
    int maxEle = freqArr.begin()->first;
    int maxValue = freqArr.begin()->second;
    
    for(auto i: freqArr) {
        cout << i.first << " -> " << i.second << endl;
        if(i.second < minValue) {
            minValue = i.second;
            minEle = i.first;
        }
        if(i.second > maxValue) {
            maxValue = i.second;
            maxEle = i.first;
        }
    }

    cout << "Min freq. ele -> " << minEle << endl;
    cout << "Max freq. ele -> " << maxEle << endl;
}

int main() {
    // basic_hash_counter_int();
    // basic_hash_counter_char();
    // map_counter_int();
    counter_min_max_freq_ele();
    return 0;
}