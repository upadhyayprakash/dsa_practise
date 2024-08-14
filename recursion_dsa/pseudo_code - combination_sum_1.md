## Pseudo Code for Combination Sum Problem:
- YouTube: https://youtu.be/OyZFFqQtu98

Let's discuss the inputs passed to this recursive function.

Input:
- `idx`: curr element's index (0 -> n) n-1 is size of array
- `arr`: Input vector<int> of distinct elements
- `n`: array length
- `target`: target integer
- `ds`: array to hold the temporary combinations
- `ans`: array of arrays to hold the valid combinations that sum up to 'target'

Following is the pseudo code for the recursive function call.

```cpp
    void combination_sum_1 (
        int idx,
        vector<int> &arr,
        int n,
        int target,
        vector<int> &ds,
        vector<vector<int>> &ans
    ) {
        // base condition. n is size of array, meaning all elements are already processed.
        IF idx = n THEN
            IF target = 0
                ans.push_back(ds) // not returning as 0s could be present in array
            
            return;
        
        // Recursive Call
        
        // pick
        IF arr[idx] <= target THEN
            ds.push_back(arr[idx]);
            CALL combination_sum_1(idx, arr, n, target-arr[idx], ds, ans) -> recursively
        
        // no-pick
        ds.pop_back(arr[idx]);
        CALL combination_sum_1(idx+1, arr, n, target, ds, ans) -> recursively
    }
```

This is the main function:

```cpp
    int main() {
        SET 'arr' to {1,2,0,100,12,-4,9} -> vector<int>
        SET 'idx' to 0 -> int
        SET 'target' to 13 -> int
        SET 'ds' to {} -> vector<int>
        SET 'ans' to {{}} -> vector<vector<int>>
        
        CALL combination_sum_1(0, arr, target, [], [][]);
        return 0;
    }
```