#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > arr) {

  //Brute
  // int n = arr.size();
  // int length = 0;

  // for(int i=0;i<n;i++){
  //   int sum = 0;

  //   for(int j=i;j<n;j++){
  //     sum += arr[j];

  //     if(sum == 0){
  //       length = max(length,j-i+1);
  //     }
  //   }
  // }
  // return length;
  //TC = O(N^2);
  //SC = O(1);

  //Optimal
  int n = arr.size();
  
  map<int,int> mp;
  int sum = 0;
  int maxLength = 0;

  for(int i=0;i<n;i++){
    sum += arr[i];
    
    if(sum == 0) maxLength = i+1;

    else{

      if(mp.find(sum) != mp.end()){
        maxLength = max(maxLength,i-mp[sum]);
      }
      else{
        mp[sum] = i;
      }
    }
  }
  return maxLength;
  //TC = O(N);
  //SC = O(N);
  
}