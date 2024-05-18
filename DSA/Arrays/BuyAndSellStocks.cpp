#include <iostream>
using namespace std;

int buyAndSellStocks( int *prices, int n ){
    int bestBuyPrice[n];
    bestBuyPrice[0] = INT32_MAX;

    for (int sellDay = 1; sellDay < n; sellDay++){
        bestBuyPrice[sellDay] = min( prices[sellDay-1], bestBuyPrice[sellDay-1]);
    }

    int maxProfit = 0;

    for( int sellDay = 0; sellDay < n ; sellDay ++){
        int profit = prices[sellDay] - bestBuyPrice[sellDay];
        maxProfit = max (maxProfit, profit);
        // cout<<maxProfit<<endl;
    }
    return maxProfit;
}

int main(){
    int n = 100000;

    int arr[n] = {7, 1, 5, 3, 6, 4};

    cout<<buyAndSellStocks(arr, n)<<endl;

    return 0;
}


//The time complexity of the above code is O(n).