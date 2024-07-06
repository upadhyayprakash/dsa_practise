# Enable Debugger using LLDB

- Install C/C++ Extension in VSCode
- Install CodeLLDB extension in VSCode
- YouTube tutorial: https://www.youtube.com/watch?v=wKjFVyDbSpA

# What is Recursion?

- A function calling itself.
- Recursion uses stack to maintain the callstack of function calls.
- We should always have a "Base Condition" (or stop condition) otherwise the function will be called infinite times and the memory will overflow causing Segmentation Fault / Stack Overflow.
- The base condition should be written at the top to exit early before the function gets call by itself.
- There can be multiple base conditions.
- Recursion Tree: The hierarchy of function calling itself and returning after each function's completion, is called Recursion Tree.
- Stack Space: the Callstack size it takes to run the complete recursion program.

# Combination Sum:
- In these problems, we are given a candidate array (distinct elements) and asked to find all combinations (array of arrays) of its elements (repeatations allowed) that sum to a 'target' value.

## Approach
- It's similar to sub-sequence technique, where we start with 'pick' or 'not pick' for each elements and then append next elements in recursion by following same 'pick' and 'not pick' technique.

- The difference here is, we're allowed to take repeat elements to build the 'target' value.

- For detailed pseudocode refer the `pseudo_code - combination_sum_1.md` file.
































# Revision Problems:
## Recursion:
- Sub-sequence:
    1. print all combination of given array of length 'n'.
        Complexity: O(n * 2^n)
        URL: https://youtu.be/AxNNVECce8c?si=Rho90k7NxTJQJh_3
    2. print all the sub-sequences with target 'sum'
        URL: https://youtu.be/eQCS_v3bw0Q?si=pXzNaKRdN4uV3vPj
    3. print ONLY first sub-sequence with target 'sum'
        Learn: How to avoid future recursion calls, basically return bool.
        URL: https://www.youtube.com/watch?v=eQCS_v3bw0Q&t=688s
    4. print COUNT of sub-sequence with target 'sum'
        Learn: return count of success with multiple recursive calls or recursion in Loop.
    