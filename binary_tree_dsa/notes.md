# Binary Tree

- At max 2 children
- Top-most node is called 'root'.
- If node has no children, it's called 'leaf' node.
- Each node has:
  - data
  - left child pointer (pointing to left subtree)
  - right child pointer (pointing to right subtree)

## Types of Binary Tree
1. Full Binary Tree:
   - Each node has "Either 0 or 2" children

2. Complete Binary Tree:
   - All levels should be completely filled, except last level.
   - Meaning, leaf node levels could be empty but should be "left-filled"
   - No restriction such as "2 children are must"

3. Perfect Binary Tree:
    - All leaf nodes should be on the same level.

4. Balanced Binary Tree:
    - Height of tree should be at max log(N).
    - Eg. if 8 nodes, then log2(8) = 3, hence 3 levels/height.
    - Used for efficient access.

5. Degenerate Tree:
    - Skewed Tree, every node has only one children.

## C++ Representation
```cpp
class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
        // constructor
        Node(int val) {
            data = val;
            left = right = nullptr;
        }
};

int main() {
    Node* root = new Node(1);
    root.left = new Node(2);
    root.right = new Node(3);
    return 0;
}
```

## Merge Two Configs
#### Tree 1

```mermaid
graph
1["ROOT - t1"] --> 2["A - alpha"]
2 --> 8["C - beta"]
2 --> 9["X - phi"]
9 --> 10["Z - mu"]
1["ROOT - t1"] --> 3["B - gamma"]
1["ROOT - t1"] --> 4["A - delta"]
1["ROOT - t1"] --> 5["C - epsilon"]
1["ROOT - t1"] --> 6["B - theta"]
1["ROOT - t1"] --> 7["D - delta"]
```

#### Tree 2

```mermaid
graph
1["ROOT - t2"] --> 2["A - apple"]
2 --> 8["C - chappal"]
2 --> 9["Y - yotta"]
1["ROOT - t2"] --> 3["E - etta"]
1["ROOT - t2"] --> 4["B - banana"]
1["ROOT - t2"] --> 5["A - aam"]
1["ROOT - t2"] --> 6["D - dollar"]
```