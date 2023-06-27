#include<bits/stdc++.h>

void f(int index, vector<int> arr, int target,vector<vector<int>> &ans, vector<int> ds, int &sum){

    //Base Case
    if(index==arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }

    //Pick
    sum += arr[index];
    ds.push_back(arr[index]);
    f(index+1,arr,target-arr[index],ans,ds,sum);
    
    //NotPick
    sum -= arr[index];
    ds.pop_back();
    f(index+1,arr,target,ans,ds,sum);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int sum = 0;

    f(0,arr,k,ans,ds,sum);
    return ans;

    //TC = O(2^n * k);
    //SC = O(k*x); k is the avg length and x is the no. of combinations
    
}