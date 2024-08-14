/**
 * Subset Sum Variant 1
 * YouTube(Striver's): https://youtu.be/rYkfBRtMJr8?si=Jit4GJFgDVxRZSAk
 * Pattern: recursion, subset
 */

#include <iostream>
using namespace std;

/**
 * TC: O(2^N + 2^NLog2^N)
 * SC: O(2^N)
 */
void get_all_subset_sum_1(int idx, int n, vector<int> &arr, int sum, vector<int> &ans) {
    // Base condition
    if(idx == n) {
        ans.push_back(sum);
        return;
    }

    // Pick ele
    get_all_subset_sum_1(idx + 1, n, arr, sum + arr[idx], ans);

    // No-Pick ele
    get_all_subset_sum_1(idx + 1, n, arr, sum, ans);
}

int main() {
    vector<int> arr = {3,1,2};

    vector<int> ans;
    get_all_subset_sum_1(0, arr.size(), arr, 0, ans);
    sort(ans.begin(), ans.end());
    for(auto i: ans)
        cout << i << " ";
    return 0;
}