#include <iostream>
using namespace std;


/**
 * Approach: Select minimum from unsorted array (i+1 till n) and swap with 'i'th element.
 */
void selection_sort() {
    int size;
    cin >> size;
    int arr[size];
    cout << "Array elements: " << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort Logic
    for(int i = 0; i < size; i++) {
        int minIdx = i;
        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        // swap 'min' element with 'i'th element
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
        // swap(arr[i], arr[minIdx]);
    }

    // print sorted array
    cout << "Sorted Array (Selection Sort): " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}


/**
 * Approach: Starting from 2nd element, insert every 'ele' in its
 * right position in sorted array by shifting other sorted elements
 * to the right.
 */
void insertion_sort() {
    // Take array input
    int size;
    cin >> size;
    int arr[size];
    cout << "Array elements: " << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort Logic
    for(int i = 1; i < size; i++) {
        int ele = arr[i]; // ele = '0'
        int j = i-1; // j = '1'
        while(j >= 0 && arr[j] > ele) {
            arr[j+1] = arr[j]; // shifting arr[] items if ele is smaller that item.
            j--;
        }
        arr[j+1] = ele; // placing the 'ele' at it's right place in sorted array.
    }
    // print sorted array
    cout << "Sorted Array (Insertion Sort): " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void bubble_sort() {
    // Take array input
    int size;
    cin >> size;
    int arr[size];
    cout << "Array elements: " << endl;
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort Logic
    for(int i = 0; i < size; i++) {
        bool flag = false;
        for(int j = 0; j < size - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(flag == false)
            break;
    }

    // print sorted array
    cout << "Sorted Array (Bubble Sort): " << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    // selection_sort();
    // insertion_sort();
    bubble_sort();
    return 0;
}