#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;

    for(auto it : mp){
        minHeap.push({it.second,it.first});

        if(minHeap.size()>k) minHeap.pop();
    }

    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;

    //TC = O(nlogk) + O(nlogk);
    //SC = O(n) + O(k);
}