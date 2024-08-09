#include <iostream>
using namespace std;

int sqrt_n(int num) {
    int low = 1;
    int high = num;
    while (low <= high) {
        long mid = ((long)low + high) / 2; // handle case of (INT_MAX + 1) / 2
        long mid_square = (long)mid * mid; // handle INT_MAX * INT_MAX
        if(mid_square == num)
            return mid;
        if(mid_square < num)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high; // return nearest integer if result is decimal value
}

int main() {
    int n = INT_MAX;
    cout << "Square root of " << n << " is:\n" << sqrt_n(n);
    return 0;
}