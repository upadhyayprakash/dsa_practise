#include <iostream>
using namespace std;

void basic_hash() {
    // Take size of array
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    
    cout << endl;    

    // Creatig hash array
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

int main() {
    basic_hash();
    return 0;
}