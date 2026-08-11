#include <stdio.h>
#include <limits.h>

int maxProfit(int* prices, int pricesSize) {
    int min_price = INT_MAX;
    int max_profit = 0;
    
    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < min_price) {
            min_price = prices[i];
        }
        else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
        }
    }
    
    return max_profit;
}

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Example 1: %d\n", maxProfit(prices1, size1)); // Expected: 5

    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Example 2: %d\n", maxProfit(prices2, size2)); // Expected: 0

    return 0;
}