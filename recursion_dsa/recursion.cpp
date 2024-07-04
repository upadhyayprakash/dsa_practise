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

void reverseArraySingleParameter(int arr[], int n, int i)
{
    // Base Condition
    if (i >= n / 2)
        return;

    // Task
    swap(arr[i], arr[n - i - 1]);

    // Recursive Call
    reverseArraySingleParameter(arr, n, ++i);
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

int fibonacci(int n) { // Time Complexity: 2^n --> Exponential (bad for fibonacci)
    if(n <= 1)
        return n;
    return (fibonacci(n-1) + fibonacci(n-2));
}

void printIntArr(vector<int> &arr) {
    if(!arr.size()) {
        cout << "{}";
    }
    for(auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
    return;
}


/**
 * A function to print all subsequence within a given array. A.k.a all permutations of the array.
 * @param i: index
 * @param printArr: subsequence array to be printed
 * @param arr: original array
 * @param n: size of original array
 * 
 * @return prints the printArr when i >= n
 */
void printSubSequence(int i, vector<int> &printArr, int arr[], int n) {
    /*
    Time Complexity: O(n x 2^n) (n is for printing and 2^n for recursive calls)
    Space Complexity: O(n) (n is the depth of recursive tree, hence auxilliary space)
    */
    // Base Condition
    if(i == n) {
        printIntArr(printArr);
        return;
    }

    // Task and Recursive Calls

    printArr.push_back(arr[i]); // add 'ele' to array
    printSubSequence(i+1, printArr, arr, n);
    printArr.pop_back(); // remove element from array, so the 'ele' is not added to subsequence
    printSubSequence(i+1, printArr, arr, n);

    /*
    You can also print the subsequence in reverse order by shifting the 2nd recursive call before adding 'ele' to 'printArr'.
    Eg.
    printSubSequence(i+1, printArr, arr, n);
    
    printArr.push_back(arr[i]); // add 'ele' to array
    printSubSequence(i+1, printArr, arr, n);
    
    printArr.pop_back(); // remove element from array, so the 'ele' is not added to subsequence
    
    */
}


/**
 * Function to print sub-sequence within given array, whose elements add up to targetSum
 * @param i: index of current element
 * @param printArr: vector used to store sub-sequence at given instance
 * @param arr: input array of elements
 * @param sum: sum of current printArr elements
 * @param targetSum: target sum for the sub-sequence
 * @param n: size of given input array
 * 
 * Approach:
 * - Idea is to create all possible sub-sequence combinations and then match every
 * combination's sum with targetSum.
 * - Apart from what we did in previous method, we also add & subtract 'ele' from the 'sum' variable
 * based on current recursive call.
 */
void printSubSequenceWithTargetSum(int i, vector<int> &printArr, int arr[], int sum, int targetSum, int n) {
    // Base Condition
    if(i == n) {
        if(sum == targetSum) {
            printIntArr(printArr);
        }
        return;
    }
    
    // Task and Recursive Call
    printArr.push_back(arr[i]); // add an element
    sum += arr[i];
    printSubSequenceWithTargetSum(i+1, printArr, arr, sum, targetSum, n);
    printArr.pop_back(); // remove the added element
    sum -= arr[i];
    printSubSequenceWithTargetSum(i+1, printArr, arr, sum, targetSum, n);
}

/**
 * Function to print 'FIRST' sub-sequence with 'targetSum'.
 * 
 * @param i: index of current element
 * @param printArr: vector used to store sub-sequence at given instance
 * @param arr: input array of elements
 * @param sum: sum of current printArr elements
 * @param targetSum: target sum for the sub-sequence
 * @param n: size of given input array
 * 
 * Approach:
 * - Difference from previous approach is, that we need to avoid future recursion call, as soon as our first sub-sequence is found.
 * - We can return a boolean flag from any specific recursion node and use that flag to avoid calling further recursions. This flag
 * will eventually go back to the top of recursion tree and exit the method.
 */
bool printFirstSubSequenceWithTargetSum(int i, vector<int> &printArr, int arr[], int sum, int targetSum, int n) {
    // Base Condition
    if(i == n) {
        if(sum == targetSum) {
            printIntArr(printArr);
            return true;
        }
        return false;
    }
    
    // Task and Recursive Call
    printArr.push_back(arr[i]); // add an element
    sum += arr[i];
    if(printFirstSubSequenceWithTargetSum(i+1, printArr, arr, sum, targetSum, n) == true)
        return true;
    
    printArr.pop_back(); // remove the added element
    sum -= arr[i];
    if(printFirstSubSequenceWithTargetSum(i+1, printArr, arr, sum, targetSum, n) == true)
        return true;
        
    return false; // this will ensure that recursion continues.
}

int getCountSubSequenceWithTargetSum(int i, int arr[], int sum, int targetSum, int n) {
    // Base condition
    if(i == n) {
        if(sum == targetSum){
            return 1;
        }
            
        return 0;
    }

    // Task and Recursive Calls
    sum += arr[i];
    int l = getCountSubSequenceWithTargetSum(i+1, arr, sum, targetSum, n); // Recursive call with 'pick' ele

    sum -= arr[i];
    int r = getCountSubSequenceWithTargetSum(i+1, arr, sum, targetSum, n); // Recursive call with 'not-pick' ele

    return (l+r);
}



int main()
{
    // Write C++ code here
    cout << "### Recursion Basic Problems ###" << endl;
    /* Take Input as 'n' */
    // cout << "\nEnter number: ";
    // int n;
    // cin >> n;
    // printNTimes(1, n, "Prakash");
    // print1ToN(1, n);
    // printNTo1(n);
    // print1ToN_BT(n);
    // printNTo1_BT(1, n);
    // cout << "Sum of first N numbers: " << sumOfFirst_N_Numbers(n) << endl;
    // cout << "Factorial of n: " << factorial(n) << endl;

    /* Reversing an Array by Recursion */

    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int arrLength = (sizeof(arr) / sizeof(*arr));

    // cout << "\nOriginal Array: " << endl;
    // for (int i = 0; i < arrLength; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << "\nReversed Array: " << endl;

    // // reverseArray(arr, 0, arrLength - 1);
    // reverseArraySingleParameter(arr, arrLength, 0);

    // for (int i = 0; i < arrLength; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    /* Reversing a Vector array by Recursion */
    // vector<int> vec = {1, 2, 3, 4, 5};

    // cout << "\nOriginal Vector: " << endl;
    // for (int i : vec)
    // {
    //     cout << i << " ";
    // }

    // reverseVectorByIterator(vec.begin(), vec.end() - 1);

    // cout << "\nReversed Array: " << endl;
    // for (int i : vec)
    // {
    //     cout << i << " ";
    // }

    /* Fibonacci using Recursion */
    // cout << "Fibonacci of n: " << fibonacci(n) << endl;

    /* Print Subsequences of a given array */

    // int arrSeq[] = {2,4,6};
    // int arrSeqLength = sizeof(arrSeq) / sizeof(*arrSeq);
    // cout << "Given Vector array: (size: " << arrSeqLength << ")" << endl;
    // for(auto i: arrSeq) {
    //     cout << i << " ";
    // }
    // cout << "\n\nSubsequence of the array: " << endl;
    // vector<int> printArrVec;
    // printSubSequence(0, printArrVec, arrSeq, arrSeqLength);

    // /* Print subsequence with Target Sum */
    
    // int arrSeq2[] = {2, 4, 6, 1, 3};
    // int arrSeqLength2 = sizeof(arrSeq2) / sizeof(*arrSeq2);
    // int targetSum = 5;
    // cout << "Given Vector array: (size: " << arrSeqLength2 << ")" << endl;
    // for(auto i: arrSeq2) {
    //     cout << i << " ";
    // }
    // cout << "\n\nSubsequence of the array: " << endl;
    // vector<int> printArrVec2;
    // // printSubSequenceWithTargetSum(0, printArrVec2, arrSeq2, 0, targetSum, arrSeqLength2);
    // printFirstSubSequenceWithTargetSum(0, printArrVec2, arrSeq2, 0, targetSum, arrSeqLength2);

    /* Print COUNT of sub-sequences where sum of its elements is 'targetSum' */

    int arrSeq3[] = {1,2,3,1};
    int arrSeqLength3 = sizeof(arrSeq3) / sizeof(*arrSeq3);
    int targetSum3 = 5;
    cout << "Given Vector array: (size: " << arrSeqLength3 << ")" << endl;
    for(auto i: arrSeq3) {
        cout << i << " ";
    }

    cout << "\nCount of Sequences with sum " << targetSum3 << ": \n" << getCountSubSequenceWithTargetSum(0, arrSeq3, 0, targetSum3, arrSeqLength3) << endl;

    return 0;
}