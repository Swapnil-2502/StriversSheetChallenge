#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   
   //Better (Hashing)
   map<int,int> mp;
   int n = arr.size();
   vector<vector<int>> ans;

   for(int i=0;i<n;i++){
      
      int rem = s - arr[i];
      if(mp.find(rem) != mp.end()){
         int count = mp[s-arr[i]];

         for(int j=0;j<count;j++){
            ans.push_back({min(rem,arr[i]),max(rem,arr[i])});
         }
      }

      mp[arr[i]]++;
   }
   sort(ans.begin(),ans.end());
   return ans;
   //TC = O(N) + O(NlogN) to sort ans array
   //SC = O(N);

   //Brute
   // int n = arr.size();

   // vector<vector<int>> ans;
   // sort(arr.begin(),arr.end());

   // for(int i=0;i<n;i++){
   //    for(int j=i+1;j<n;j++){
   //       if(arr[i] + arr[j] == s) ans.push_back({arr[i],arr[j]});
   //    }
   // }
   // return ans;
   //TC = O(NlogN) + O(N*N);
   //SC = O(1);
}