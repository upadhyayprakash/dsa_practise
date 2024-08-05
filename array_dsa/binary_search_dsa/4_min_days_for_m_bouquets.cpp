/**
 * Find minimum number of days to make 'm' bouquets.
 * YouTube (Striver's): https://www.youtube.com/watch?v=TXAuxeYBTdg
 * Pattern: Binary Search on 'Answers'
 */

#include <iostream>
#include <algorithm>
using namespace std;

bool is_bouquets_possible(vector<int> &arr, int day, int m, int k) {
    int counter = 0;
    int ready_bouquets = 0;
    for(auto i: arr) {
        if(i <= day)
            counter++;
        else {
            ready_bouquets += counter / k; // reduce ready bouquets from target bouquets 'm'
            counter = 0;
        }
    }
    ready_bouquets += counter / k;
    
    if(ready_bouquets >= m)
        return true;
    else
        return false;
}

/**
 * Approach:
 * 0. Another BS on Answer scenario, as answer lies between minEle and maxEle of array.
 * 1. Hence, the possible answer range is [minEle, maxEle].
 * 2. For every possible answer value, keep a 'counter' and increment it for
 * every bloomed adjacent 'ele'. Stop the counter if an non-bloomed 'ele' is encountered.
 * 3. For every 'counter' check how many bouquets can be found. (counter % k)
 * 4. Reset the 'counter' and keep doing it. until all 'm' bouquets are made.
 * 'possible answer'.
 
 */
int get_min_days_for_m_bouquets(vector<int> days, int m, int k) { // TC: O(N * Log2(maxEle - minEle + 1)), SC: O(1)
    int n = days.size();
    if(m * k > n) return -1; // impossible case, return -1

    int low = *min_element(days.begin(), days.end());
    int high = *max_element(days.begin(), days.end());

    while(low <= high) {
        int mid = (low + high) / 2;
        if(is_bouquets_possible(days, mid, m, k))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> bloom_days = {7,7,7,7,13,11,12,7};
    int m = 2; // num of bouquets
    int k = 3; // size of each bouquet
    cout << "Min. number of days:\n" << get_min_days_for_m_bouquets(bloom_days, m, k);
    return 0;
}