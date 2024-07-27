#include <iostream>
#include <queue>
using namespace std;

void print_pq_default(priority_queue<int> pq) {
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void print_pq(priority_queue<int, vector<int>, greater<int>> pq) {
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    cout << "Priority Queue (STL):\n";
    priority_queue<int> pqMax; // default maxHeap STL
    pqMax.push(1);
    pqMax.push(4);
    pqMax.push(3);
    pqMax.push(2);
    cout << "maxHeap:\n";
    print_pq_default(pqMax);

    priority_queue<int, vector<int>, greater<int>> pqMin; // minHeap STL
    pqMin.push(1);
    pqMin.push(4);
    pqMin.push(3);
    pqMin.push(2);
    cout << "minHeap:\n";
    print_pq(pqMin);

    cout << "Top Element maxHeap:\n";
    cout << pqMax.top() << endl;

    cout << "Top Element minHeap:\n";
    cout << pqMin.top() << endl;

    return 0;
}