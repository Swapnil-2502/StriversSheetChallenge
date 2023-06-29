#include <bits/stdc++.h> 

//Recursion
void f(int index,string &s,vector<string> &ans){

    //Base Case
    if(index == s.size()){
        ans.push_back(s);
        return;
    }

    for(int i=index;i<s.size();i++){
        swap(s[i],s[index]);
        f(index+1,s,ans);
        swap(s[i],s[index]);
    }
}
//TC = O(N! * N)
//SC = O(N)

vector<string> findPermutations(string &s) {

    //BackTracking
    int n = s.size();
    vector<string> ans;
    vector<string> ds;
    int freq[n];

    f(0,s,ans);

    return ans;
   
}