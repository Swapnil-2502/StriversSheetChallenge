#include<bits/stdc++.h>
void f(int index,vector<int> &num,vector<int> &ans,int n,int sum){

	//Base Case 
	if(index == n){
		ans.push_back(sum);
		return;
	}

	//Pick 
	f(index+1,num,ans,n,sum+num[index]);
	//NotPick
	f(index+1,num,ans,n,sum);
}


vector<int> subsetSum(vector<int> &num){
	vector<int> ans;	
	f(0,num,ans,num.size(),0);
	sort(ans.begin(),ans.end());
	return ans;

	//TC = O(2^n) + O(2^n log(2^n));
	//SC = O(2^n);
}