# Basic Sorting Methods
- Selection Sort -> O(n^2)
- Insertion Sort -> O(n^2)
- Bubble Sort -> O(n^2)

# Advanced Sorting Methods
- Merge Sort  -> O(N*logN)
- Quick Sort -> 


# DSA Approach:
- Explain solution
- Pseudo Code
- Dry Run
- Coding

# Merge Sort
- 'Divide' and 'Merge' technique.
- Uses recursion
- Uses an extra 'temp' array during 'merge' operations.
- Time Complexity: O(N * logN)
- Space Complexity: O(N) -> used by 'temp' array

# Quick Sort
- 'Divide' and 'Conquer' technique.
- Uses recursion
- Doesn't use any extra space.
- Time Complexity: O(N * logN)
- Space Complexity: O(1) -> No extra space other than recursion stack memory.
## Quick Sort Approach:
    1. Pick a Pivot and place it on its correct position by using "2-pointers":
        - left pointer: starts with 0 and finds an ele that's greater than pivot
        - right pointer: starts with last arr ele, and finds an ele that's smaller than pivot
        - AND THEN, WE SWAP THESE TWO ELEMENTS.
        - We then continue moving 'left' pointer forward and 'right' pointer backward, and swap the elements found, until the left and right cross each other.
        - Once they cross, we SWAP THE PIVOT with 'right' pointer element.
    2. Do it recursively similar to merge sort 'divide' step.
