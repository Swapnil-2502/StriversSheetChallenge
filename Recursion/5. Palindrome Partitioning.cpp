#include <bits/stdc++.h> 

bool isPermutation(int start, int end,string &s){

    while(start<=end){
        if(s[start] != s[end]) return false;

        start++;end--;
    }

    return true;
}

void f(int index,string &s, vector<vector<string>> &ans,vector<string> &ds){

    //Base Case
    if(index == s.size()){
        ans.push_back(ds);
        return;
    }


    for(int i=index;i<s.size();i++){
        if(isPermutation(index,i,s)){
            ds.push_back(s.substr(index,i-index+1));
            f(i+1,s,ans,ds);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> ds;

    f(0,s,ans,ds);

    return ans;
    //TC = O(2^n*k*(n/2));
    //SC = O(k*x);
}