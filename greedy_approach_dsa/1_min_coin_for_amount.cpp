#include <iostream>
#include <vector>
using namespace std;

vector<int> get_min_coins_for_amount(int amount) {
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    vector<int> ans;
    int i = coins.size() - 1; // '8'
    int cnt = 0;
    while(amount > 0) { // Time Complexity: O(v) -> v is types of coins
        if(coins[i] <= amount) {
            amount -= coins[i];
            ans.push_back(coins[i]);
            cnt++;
        } else
            i--;
    }
    return ans;
}

int main() {
    int amount = 49;
    vector<int> a = {};
    cout << "Min. coins required for amount " << amount << " is:\n";
    vector<int> result = get_min_coins_for_amount(amount);
    for(auto i: result) {
        cout << i << " ";
    }
    
    return 0;
}