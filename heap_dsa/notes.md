# Priority Queue
## Summary
- Every `ele` has a priority attached to it.
- `dequeue` operation happens based on priority.
- For same priority elements, order is maintained.

Priority queues can be implemented using *"Binary Heap"* which have following properties:
- Binary Heap is a *"Complete tree"*, meaning every level is filled and last level is filled from *left-to-right*.
- This makes it easier to use array for storing elements for faster retrievals.
    - Left Child: `2n+1`
    - Right Child: `2n+2`, where 'n' is node's index
    - Parent: `(i-1)/2`

## Operations on Priority Queue:
- Insert (`push()`) -> adds to pq based on element's priority
- Remove (`pop()`) -> extracts the max priority element
- Peak (`top()`) -> gets the max priority element

## Implementation of Priority Queue using Binary Heap

Helper methods:
- parent()
- leftChild()
- rightChild()
- shiftUp()
- shiftDown()

Using these helper methods, we can implement the priority queue operations such as `push()`, `pop()`, `top()`. Check the code in `pq_using_binary_heap.cpp`.