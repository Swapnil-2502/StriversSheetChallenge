#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	
    //Optimal
	//Linked List Cycle Method
	int slow = arr[0];
	int fast = arr[0];

	do {
		slow = arr[slow];
		fast = arr[arr[fast]];
	} while (slow != fast);

	fast = arr[0];
	while (slow != fast) {
		slow = arr[slow];
		fast = arr[fast];
	}
	return slow;
	// //TC = O(N)
	// //SC = O(1)

	//Brute
	vector<int> freq(n,0);

	for(int i=0;i<n;i++){
		if(freq[arr[i]] == 0) freq[arr[i]]++;
		else return arr[i];
	}
	//TC = O(N)
	//SC = O(N)
}
