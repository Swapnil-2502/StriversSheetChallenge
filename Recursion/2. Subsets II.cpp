#include <bits/stdc++.h> 
// void f(int index, set<vector<int>> &st,vector<int> &res,vector<int> &arr){
//     //Base Case
//     if(index == arr.size()){
//         st.insert(res);
//         return;
//     }

//     res.push_back(arr[index]);
//     f(index+1,st,res,arr);
//     res.pop_back();
//     f(index+1,st,res,arr);
// }

void f(int index,vector<vector<int>> &ans,vector<int> &ds,vector<int> &arr){
    ans.push_back(ds);

    for(int i=index;i<arr.size();i++){
        if(i!=index && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        f(i+1,ans,ds,arr);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // sort(arr.begin(),arr.end());
    // set<vector<int>> st;
    // vector<int> res;

    // f(0,st,res,arr);

    // vector<vector<int>> ans(st.begin(),st.end());

    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    f(0,ans,ds,arr);

    return ans;
    //TC = O(2^n * k); k == size of set
    //SC = O(2^n * k);
}