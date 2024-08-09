/**
 * Largest rectangle in a histogram
 * YouTube (Striver's): https://www.youtube.com/watch?v=Bzat9vgD0fs
 */

#include <iostream>
#include <stack>
using namespace std;

int get_largest_rect_area_optimal(vector<int> &heights) {
    stack < int > st;
    int maxA = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
        }
        st.push(i);
    }
    return maxA;
}

vector<int> get_previous_smaller_elements(vector<int> &arr) {
    vector<int> pse(arr.size());
    stack<pair<int, int>> st;
    for(int i = 0; i < arr.size(); i++) {
        while(!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        if(!st.empty())
            pse[i] = st.top().second;
        else
            pse[i] = -1;
        st.push({arr[i], i});
    }
    return pse;
}

vector<int> get_next_smaller_elements(vector<int> &arr) {
    vector<int> nse(arr.size());
    int n = arr.size();
    stack<pair<int, int>> st;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top().first >= arr[i]) {
            st.pop();
        }
        if(!st.empty())
            nse[i] = st.top().second;
        else
            nse[i] = n;
        st.push({arr[i],i});
    }
    return nse;
}

/**
 * Approach: Using NSE, PSE and stack. TC: O(5N), SC: O(4N)
 */
int get_largest_rect_area_better(vector<int> &heights) {
    int maxArea = 0;
    vector<int> pse = get_previous_smaller_elements(heights); // idx of previous smaller elements
    vector<int> nse = get_next_smaller_elements(heights); // idx of next smaller elements
    
    for(int i = 0; i < heights.size(); i++) {
        maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << "Largest rectangle area(Better):\n" << get_largest_rect_area_better(heights);
    cout << "\nLargest rectangle area(Optimal):\n" << get_largest_rect_area_optimal(heights);
    return 0;
}