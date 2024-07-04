# Hashing
Striver's Video (Basic): https://www.youtube.com/watch?v=KEs5UyBJ39g

- An frequency array can be used as a counter for input arr.
- The size of freqArr can be determined from the maxEle of input array.
    freqArr[maxEle+1]
- For character hashing, we can rely on array[255+1] as there're only 255 ASCII characters.
- But for integers, size of `freqArr[size]` is limited, hence for a huge `maxEle`, it's not possible to create a freqArr. Eg. 10^7 or more. Hence array's are not suitable for all counting frequency in huge range of integers.
- Hence, we use std::map from C++ STL library. Which can store <key, value> pair which are sorted by default.

## Map
- Map stores key values pair in sorted order of `key`.
- 