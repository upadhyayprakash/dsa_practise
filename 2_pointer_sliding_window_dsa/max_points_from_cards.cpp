#include<iostream>
using namespace std;

int max_points_from_cards(vector<int> &arr, int n, int k) {
    /*
    Input:
        arr -> {6,2,3,4,7,2,1,7,1}
        k -> 4
    */
    
    int l = k-1;
    int r = n;
    int maxSum = 0;
    for(int i = 0; i <= l; i++) {
        maxSum += arr[i];
    }

    int sum = maxSum;
    int i = 1;
    while(i <= k) {
        sum -= arr[k-i];
        sum += arr[n-i];
        maxSum = max(maxSum, sum);
        i++;
    }
    
    return maxSum;
}

int main() {

    vector<int> arr = {6,2,3,4,7,2,1,7,1};
    int k = 4;
    cout << "Max points from " << k << " picked cards is:\n";
    cout << max_points_from_cards(arr, arr.size(), k);
    return 0;
}