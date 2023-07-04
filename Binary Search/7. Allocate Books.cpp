#include <bits/stdc++.h> 

bool isPossible(int n, int m,vector<int> time,long long int mid){
	long long int countdays = 1;
	long long int timeSum = 0;

	for(int i=0;i<m;i++){

		if(timeSum + time[i] <= mid){
			timeSum+=time[i];
		}
		else{
			countdays++;
			if(countdays>n || time[i]>mid){
				return false;
			}
			else{
				timeSum=time[i];
			}
		}
	}
	return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long int start = 0;
	long long int sum = 0;

	for(int i=0;i<m;i++){
		sum += time[i];
	}

	long long int end = sum;
	long long int ans = -1;

	while(start<=end){
		long long int mid= (start+end) >> 1;

		if(isPossible(n,m,time,mid)){
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return ans;
	//TC = O(nlogm);
	//SC = O(1);
}