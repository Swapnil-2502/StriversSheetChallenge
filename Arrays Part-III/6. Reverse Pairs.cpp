#include <bits/stdc++.h> 

int Merge(vector<int> &arr, int low, int mid, int high){

	int total = 0;
	int j = mid+1;

	for(int i=low;i<=mid;i++){
		while(j<=high && arr[i] > 2*arr[j]){
			j++;
		}
		total += (j - (mid+1));
	}

	vector<int> temp;
	int left = low;
	int right = mid+1;

	while(left<=mid && right<=high){

		if(arr[left] < arr[right]){
			temp.push_back(arr[left]);
			left++;
		}
		else{
			temp.push_back(arr[right]);
			right++;
		}
	}

	while (left <= mid) {
    temp.push_back(arr[left++]);
	}

	while (right <= high) {
		temp.push_back(arr[right++]);
	}

	for(int i=low;i<=high;i++){
		arr[i] = temp[i - low];
	}

	return total;

}

int MergeSort(vector<int> &arr, int low, int high){

	if(low >= high) return 0;
	int mid = (low + high)/2;
	int revPairs = MergeSort(arr,low,mid);
	revPairs += MergeSort(arr,mid+1,high);
	revPairs += Merge(arr,low,mid,high);

	return revPairs;
}

int reversePairs(vector<int> &arr, int n){

	//Optimal
	return MergeSort(arr,0,arr.size()-1);
	
	// //Brute
	// int count = 0;

	// for(int i=0;i<n-1;i++){
	// 	for(int j=i+1;j<n;j++){
	// 		if(arr[i] > 2*arr[j]) count++;
	// 	}
	// }
	// return count;
	// //TC = O(N*N);
	// //SC = O(1);
}