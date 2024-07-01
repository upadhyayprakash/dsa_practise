// Online C++ compiler to run C++ program online
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void printNTimes(int i, int N, string name)
{ // Time Complexity: O(n)
    // Base Condition
    if (i > N)
        return;

    // Task to perform
    cout << name << endl;

    // Recursive call
    printNTimes(i + 1, N, name);
}

void print1ToN(int i, int N)
{
    // Base Condition
    if (i > N)
        return;

    // Task
    cout << i << endl;

    // Recursive Call
    print1ToN(i + 1, N);
}

void printNTo1(int i)
{
    if (i < 1)
        return;
    cout << i << endl;
    printNTo1(i - 1);
}

void print1ToN_BT(int N)
{ // Using backtracking
    // Base Condition
    if (N < 1)
        return;

    // Recursive Call
    print1ToN_BT(N - 1);

    // Task
    cout << N << endl;
}

void printNTo1_BT(int i, int N)
{ // Using Backtracking
    if (i > N)
        return;

    // Recursive Call
    printNTo1_BT(i + 1, N);

    // Task
    cout << i << endl;
}

int sumOfFirst_N_Numbers(int n)
{
    // Base condition
    if (n < 1)
        return n;

    // Task: add 'n' to result
    return (n + sumOfFirst_N_Numbers(n - 1));
}

/* Dry Run
f(3) -> f(2) -> f(1) -> f(0)

Returned Value:
0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
*/

int factorial(int n)
{
    if (n <= 1)
        return 1;
    return (n * factorial(n - 1));
}

void reverseArray(int arr[], int left, int right)
{
    // Eg. Input: [1,2,3,4,5]

    // Base Condition
    if (left >= right)
        return;

    // Task: Swap 'left' and 'right' elements
    int swap = arr[left];
    arr[left] = arr[right];
    arr[right] = swap;
    // swap(arr[left], arr[right]);

    // Recursive Call
    reverseArray(arr, ++left, --right);
}

void reverseVectorByIterator(vector<int>::iterator start, vector<int>::iterator end)
{
    // Eg. Input: {1,2,3,4,5}

    // Base Condition
    if (start >= end)
        return;

    // Task: Swap elements at 'start' and 'end' pointers
    swap(*start, *end);

    // Recursive Call
    reverseVectorByIterator(++start, --end);
}

int main()
{
    // Write C++ code here
    cout << "### Recursion Basic Problems ###" << endl;
    cout << "\nEnter number: ";
    int n;
    cin >> n;
    // printNTimes(1, n, "Prakash");
    // print1ToN(1, n);
    // printNTo1(n);
    // print1ToN_BT(n);
    // printNTo1_BT(1, n);
    // cout << "Sum of first N numbers: " << sumOfFirst_N_Numbers(n) << endl;
    // cout << "Factorial of n: " << factorial(n) << endl;

    /* Reversing an Array by Recursion */
    // int arr[] = {1,2,3,4,5,6};
    // int arrLength = (sizeof(arr)/sizeof(*arr));

    // cout << "\nOriginal Array: " << endl;
    // for(int i = 0; i < arrLength; i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << "\nReversed Array: " << endl;
    // reverseArray(arr, 0, arrLength-1);
    // for(int i = 0; i < arrLength; i++) {
    //     cout << arr[i] << " ";
    // }

    /* Reversing a Vector array by Recursion */
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << "\nOriginal Vector: " << endl;
    for (int i : vec)
    {
        cout << i << " ";
    }

    reverseVectorByIterator(vec.begin(), vec.end() - 1);

    cout << "\nReversed Array: " << endl;
    for (int i : vec)
    {
        cout << i << " ";
    }

    return 0;
}