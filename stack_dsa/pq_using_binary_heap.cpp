#include <iostream>
#include <vector>
using namespace std;

/**
 * Priority Queue: Binary Heap Implementation
 * Operations:
 * - push(priority) -> priority can be as simple as 'ele' value itself.
 * - pop()
 * - top()
 * - remove(i)
 * - update(i, priority)
 * - size(): size of priority queue for '1' based indexing
 */

class PriorityQueue {
    private:
        vector<int> pq;
    
    public:
        int size() {
            return pq.size(); // for '1' based indexing
        }

        int parent(int i) {
            return (i-1)/2;
        }

        int leftChild(int i) {
            return (2 * i) + 1;
        }

        int rightChild(int i) {
            return (2 * i) + 2;
        }

        void shiftUp(int i) {
            while(i > 0 && pq[parent(i)] < pq[i]) {
                swap(pq[parent(i)], pq[i]);
                i = parent(i);
            }
        }

        void shiftDown(int i) {
            int swapIndex = i;
            
            int leftIndex = leftChild(i);
            int rightIndex = rightChild(i);

            if(leftIndex < size() && pq[leftIndex] > pq[swapIndex])
                swapIndex = leftIndex;
            
            if(rightIndex < size() && pq[rightIndex] >= pq[swapIndex])
                swapIndex = rightIndex;

            if(i != swapIndex) {
                swap(pq[i], pq[swapIndex]);
                shiftDown(swapIndex);
            }
        }

        void print_pq() {
            for(auto i: pq) {
                cout << i << " ";
            }
            cout << endl;
        }

        void push(int priority) {
            pq.push_back(priority);
            shiftUp(pq.size() - 1);
        }

        int pop() {
            int result = pq[0];
            
            int lastEle = pq.back();
            pq.pop_back(); // remove the last ele
            pq[0] = lastEle; // add last ele to heap 'root'
            
            shiftDown(0); // re-arrange
            
            return result;
        }

        int top() {
            return pq[0];
        }

        void remove(int i) {
            pq[i] = top() + 1;
            shiftUp(i);
            pop();
        }

        void update(int i, int priority) {
            int oldValue = pq[i];
            pq[i] = priority;
            if(priority > oldValue)
                shiftUp(i);
            else
                shiftDown(i);
        }
};

int main() {
    PriorityQueue* pq = new PriorityQueue();
    pq->push(1);
    pq->push(8);
    pq->push(5);
    pq->push(2);
    cout << "Priority Queue:\n";
    pq->print_pq();

    cout << "\nTop of PQ:\n" << pq->top() << endl;

    cout << "\nPQ after removing 2:\n";
    pq->remove(1);
    pq->print_pq();
    cout << "\nRestoring...\n";
    pq->push(2);
    pq->print_pq();
    cout << "\nUpdating 5 to 11:\n";
    pq->update(2, 11);
    pq->print_pq();
    cout << "\nSize of PQ:\n" << pq->size();

    return 0;
}