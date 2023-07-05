#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	priority_queue<int> maxHeap;
	priority_queue<int,vector<int>,greater<int>> minHeap;

	for(int i=0;i<n;i++){

		maxHeap.push(arr[i]);
		minHeap.push(arr[i]);

		if(maxHeap.size()>k){
			maxHeap.pop();
		}
		if( minHeap.size()>k){
			minHeap.pop();
		}

		
	}
    vector<int> ans = { maxHeap.top(), minHeap.top() };
	return ans;
	//TC = O(nlogk);
	//SC = O(k);

	// sort(arr.begin(), arr.end());
	// vector<int> ans = {arr[k-1], arr[n-k]};
	// return ans;
}