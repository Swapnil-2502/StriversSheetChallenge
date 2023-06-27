#include<bits/stdc++.h>

void f(int index,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &ds){

	//BASE CASE
	if(target == 0){
		ans.push_back(ds);
		return;
	}
	



	for(int i=index;i<arr.size();i++){

		if(i>index && arr[i] == arr[i-1]) continue;

		if(arr[i] > target) break;

		ds.push_back(arr[i]);
		f(i+1,arr,target-arr[i],ans,ds);
		ds.pop_back();
	}
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	
	vector<vector<int>> ans;
	vector<int> ds;
	sort(arr.begin(),arr.end());
	f(0,arr,target,ans,ds);

	return ans;
}
