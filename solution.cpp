#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <limits>
#include <utility> // pair
#include <tuple>
#include <algorithm>
#include <climits>

// g++ -std=c++11 solution.cpp

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.size() <= 0 ) {
            return -1;
        }
        if (coins.size() == 1) {
            if(amount == coins[0]) {
                return 1;
            }
        }
        // use to record how many coins for assembling the each ammount
        int *dp = new int[amount + 1];
        
        // initialization
        dp[0] = 0;  // if the amount is 0, we need 0 coin to assemble the amount
        for (int i = 1; i <= amount; ++i)
        {
            dp[i] = -1;  // -1 means no coins could be assembled the amount
        }

        //*** calculate the minimum number for assemble each amount ***
        for (int i = 0; i <= amount; ++i) { // count from the minimum amount
            int min = INT_MAX;
            printf("=======================\n");
            for (int coin : coins) { // go through all coins
                // dp[i - coin] means the minimum size of the coins to assemble the previous amount
                printf("coin: %d\n", coin);
                if (i - coin >= 0 && dp[i - coin] != -1) {
                    int tmp = dp[i - coin] + 1;  // add one more coin
                    if (tmp < min) {
                        min = tmp; // the minimum quantity for assembling the ammount
                        printf("dp[%d - %d]: %d\n",i, coin, dp[i - coin]);
                        printf("min: %d coin: %d amount: %d\n", min, coin, i);
                    }
                }
            }

            // if min != INT_MAX means that the current amount could be assembled
            if (min != INT_MAX)
                dp[i] = min;
            printf("The minimum quantity to assemble %d: %d\n", i, dp[i]);
        }
        return dp[amount];
    }
};


int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> coins{ 1, 6, 7 };
    int amount = 18;
    printf("output:%d\n", s -> coinChange(coins, amount));
}