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

        // remove 0 from coins
        coins.erase(std::remove(coins.begin(), coins.end(), 0), coins.end());

        //for (auto i = coins.begin(); i != coins.end(); ++i)
        //    std::cout << *i << ' ';
        //printf("start, rest_amount:%d\n", rest_amount);

        int output = 0;
        int best_choose_coin = 0;
        int rest_amount = amount;
        bool no_proper_coin = true;

        while(true) {
            best_choose_coin = 0;
            no_proper_coin = true;
            for (int i = 0 ; i < coins.size(); i++) {
                if ( (rest_amount - coins[i]) >= 0 ) {
                    if (rest_amount - coins[i] <= rest_amount - best_choose_coin) {
                        best_choose_coin = coins[i];
                        no_proper_coin = false;
                        printf("[%d] best_choose_coin:%d\n", i, best_choose_coin);
                    }
                }
            }

            if (no_proper_coin) {
                if(rest_amount > 0) {
                    return -1;
                }
                return output;
            } else {
                rest_amount = rest_amount - best_choose_coin;
                output++;
                printf("rest_amount: %d, best_choose_coin: %d\n", rest_amount, best_choose_coin);
            }
        }
        return output;
    }
};


int main(int argc, char *argv[]) {
    Solution *s = new Solution();
    std::vector<int> coins{ 0, 1, 2, 3, 5, 7, 12};
    int amount = 11;
    printf("output:%d\n", s -> coinChange(coins, 11));
}