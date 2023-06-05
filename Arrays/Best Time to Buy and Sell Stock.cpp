#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    

    //Optimal 
    int n = prices.size();
    int MaxProfit = 0;
    int minPrice = INT_MAX;

    for(int i=0;i<n;i++){
        minPrice = min(minPrice , prices[i]);
        MaxProfit = max(prices[i]-minPrice, MaxProfit);
    }
    return MaxProfit;
    //TC = O(N)
    //SC = O(1)

    //Brute
    //Use two loops to track transcations and maintain max profit
    // int n = prices.size();
    // int maxProfit = 0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(prices[j]>prices[i]){
    //             maxProfit = max(prices[j]-prices[i],maxProfit);
    //         }
    //     }
    // }
    // return maxProfit;
    //TC = O(N*N)
    //SC = O(1)
}