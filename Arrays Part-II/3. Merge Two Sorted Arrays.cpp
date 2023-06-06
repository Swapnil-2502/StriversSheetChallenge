#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	
	vector<int> merged;
	int ind1 = 0;
	int ind2 = 0;

	while(ind1 < m && ind2 <n){
		if(arr1[ind1] < arr2[ind2]){
			merged.push_back(arr1[ind1]);
			ind1++;
		}
		else{
			merged.push_back(arr2[ind2]);
			ind2++;
		}

	}
	while(ind1 < m) merged.push_back(arr1[ind1++]);

	while(ind2 < n) merged.push_back(arr2[ind2++]);

	return merged;
	//TC = O(n+m);
	//SC = O(n+m);

    //Another approach without space
	// int ind1 = m+n-1;
	// int ind2 = n-1;

	// while(ind2 >= 0){
		
	// 	arr1[ind1] = arr2[ind2];
	// 	ind1--;ind2--;
	// }	
	// sort(arr1.begin(),arr1.end());
	// return arr1;
	// //TC = O((n+m)*log(n+m)) + O(n);
	// //SC = O(1);
}