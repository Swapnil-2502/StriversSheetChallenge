#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    

    //BRUTE
    // int ans = 1;
    // sort(arr.begin(),arr.end());

    // int prev = arr[0];
    // int curr = 1;

    // for(int i=0;i<n;i++){

    //     if(arr[i] == prev+1){
    //         curr++;
    //     }
    //     else if(arr[i] != prev){
    //         curr = 1;
    //     }
    //     prev = arr[i];
    //     ans = max(ans,curr);
    // }
    // return ans;
    //TC = O(NlogN) + O(N);
    //SC = O(1);

    //Optimal
    int ans = 1;

    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it : arr){
        if(!st.count(it-1)){
            int currNum = it;
            int currCount = 1;

            while(st.count(currNum + 1)){
                currNum += 1;
                currCount += 1;
            }
             ans = max(ans,currCount);
        }
       
    }
    return ans;
    //TC = O(N);
    //SC = O(N);
    //Used unordered_set to lower TC;
   
    
}