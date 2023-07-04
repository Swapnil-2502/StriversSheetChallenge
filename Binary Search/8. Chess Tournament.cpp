#include <bits/stdc++.h> 

bool isPossible(vector<int> positions, int Players, int n, int mid){

	int count = 1;
	int lastPosition = positions[0];

	for(int i=0;i<n;i++){
		if(positions[i] - lastPosition >= mid){
			count++;
			lastPosition = positions[i];
		}
	}
	if(count >= Players) return true;
	return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	
	sort(positions.begin(),positions.end());

	int low = 1, high = positions[n-1]-positions[0];

	while(low<=high){

		int mid = (low+high)>>1;

		if(isPossible(positions,c,n,mid)){
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	return high;
	//TC = O(N*log(M))
	//SC = O(1)
}