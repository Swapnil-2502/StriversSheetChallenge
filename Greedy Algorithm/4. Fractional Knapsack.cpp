#include <bits/stdc++.h> 

bool comp(pair<int, int>a, pair<int, int>b){
    double r1 = (double)a.second/(double)a.first;
    double r2 = (double)b.second/(double)b.first;
    return r1>r2;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(),items.end(),comp);

    int currWeight = 0;
    double finalValue = 0.0;

    for(int i=0;i<n;i++){
        if(currWeight + items[i].first <= w){
            currWeight += items[i].first;
            finalValue += items[i].second;
        }
        else{
            int remain = w - currWeight;
            finalValue += (items[i].second / (double)items[i].first)*(double)remain;
            break;
        }
    
    }

    return finalValue;
    //TC = O(nlogn) + O(n);
    //SC = O(1);
}