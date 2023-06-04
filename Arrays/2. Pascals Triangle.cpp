#include <bits/stdc++.h>

vector<long long int> generateRow(int row){
  long long num = 1;
  vector<long long int> ans;
  ans.push_back(1);

  for(int i=1;i<row;i++){
    num = num * (row-i);
    num = num /i;
    ans.push_back(num);
  }

  return ans;
}

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> Ans;
  for(int i=1;i<=n;i++){
    Ans.push_back(generateRow(i));
  }

  return Ans;
}
//TC = O(n*n)
//SC = O(1)