# Hashing
Striver's Video (Basic): https://www.youtube.com/watch?v=KEs5UyBJ39g

- An frequency array can be used as a counter for input arr.
- The size of freqArr can be determined from the maxEle of input array.
    freqArr[maxEle+1]
- For character hashing, we can rely on array[255+1] as there're only 255 ASCII characters.
- But for integers, size of `freqArr[size]` is limited, hence for a huge `maxEle`, it's not possible to create a freqArr. Eg. 10^7 or more. Hence array's are not suitable for all counting frequency in huge range of integers.
- Hence, we use std::map from C++ STL library. Which can store <key, value> pair which are sorted by default.

## Map
- Map stores <key,values> pair in sorted order of `key`. Key could be simple data types as well as other types like pair<>
    - Time Complexity: O(logN) - It uses Red-Black tree for storage.
- Unordered_Map stores <key,value> pair in random order. Key can be only single value data type. (int, char, double etc.)
    - Best/Avg Time Complexity: O(1), but in a very rare scenario, Worst case is O(N).
    - Worst case happens only when high key collisions happen and elements are stored as linear chain(like a LinkedList), very unlikely though.
- Most of the time, use `unordered_map`, but if it takes lot of time (or fails, due to internal key collisions), switch to `map`
- 

## Hashing
- Large range of intergers can't be stored in a "limited-sized" array.
- Hence we use "Division" based hashing (modulo)
- Eg. for int 139 and fixed size array of length 10, we'll perform modulo of 130%10, we'll get 9, hence increment count for 9.
- When a query for '139' comes, we can calcualte hash of 139, by using same modulo formula, and look up the frequency array for '9', and return '1' as its count.

