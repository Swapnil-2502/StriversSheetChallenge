#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	
	//Optimal Moore’s Voting Algorithm:
	int count = 1;
	int element=arr[0];

	for(int i=1;i<n;i++){
		if(count == 0){
			count = 1;
			element = arr[i];
		}
		else if(arr[i] == element) count++;
		else if(arr[i] != element) count--;
	}

	
	int count2=0;

	for(int i=0;i<n;i++){
		if(arr[i] == element) count2++;
	}
	if(count2 > (n/2)) return element;
	
	return -1;
	//TC = O(2 * N);
	//SC = O(1);

    

	// //Better
	// int reqFreq = n / 2;
	// unordered_map<int,int> mp;

	// for(int i=0;i<n;i++){
	// 	mp[arr[i]]++;

	// 	if(mp[arr[i]] > reqFreq) return arr[i];

	// }
	// return -1;
	// //TC = O(nlogn) + O(n);
	// //SC = O(n);

	// //Brute
	// for(int i=0;i<n;i++){
	// 	int count = 0;

	// 	for(int j=i+1;j<n;j++){
	// 		if(arr[j] == arr[i]) count++;
	// 	}

	// 	if(count >= (n/2)) return arr[i];
	// }

	// return -1;
	// //TC = O(n*n);
	// //SC = O(1);

}