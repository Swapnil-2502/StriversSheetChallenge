#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;

    //{element,{arrayNumber,Index}};
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
    greater<pair<int,pair<int,int>>>> minHeap;

    //Push all the first elements of arrays
    for(int i=0;i<k;i++){
        minHeap.push({kArrays[i][0],{i,0}});
    }

    while(!minHeap.empty()){
        pair<int,pair<int,int>> top = minHeap.top();
        minHeap.pop();

        int value = top.first;
        int arrayNumber = top.second.first;
        int index = top.second.second;

        ans.push_back(value);

        if(index+1 < kArrays[arrayNumber].size()){
            minHeap.push({kArrays[arrayNumber][index+1],{arrayNumber,index+1}});
        }
    }
    return ans;
    //TC = O(N*K)*(logk);
    //SC = O(N*K);
}
