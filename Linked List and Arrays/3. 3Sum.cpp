#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	
	//Brute (using three loops)
	set<vector<int>> st;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k = j+1;k<n;k++){
				if(arr[i] + arr[j] + arr[k] == K){
					vector<int> temp = {arr[i],arr[j],arr[k]};
					sort(temp.begin(),temp.end());
					st.insert(temp);
				}
				
			}
		}
	}
	vector<vector<int>> ans(st.begin(),st.end());
	return ans;
	//TC = O(N^3 * log(no of triplets));
	//SC = 2*O(no of triplets);

	//Better (Hashing)
	set<vector<int>> st;

	for(int i=0;i<n;i++){
		set<int> hashset;
		for(int j=i+1;j<n;j++){
			int third = K -(arr[i]+arr[j]);
			
			if(hashset.find(third) != hashset.end()){
				vector<int> temp = {arr[i],arr[j],third};
				sort(temp.begin(),temp.end());
				st.insert(temp);
			}
			hashset.insert(arr[j]);
		}
	}
	vector<vector<int>> ans(st.begin(),st.end());
	return ans;
	//TC = O(N^2 * log(M));
	//SC = O(N) + O(no of triplets)*2;

	//Optimal (2 pointer approach)
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());

	for(int i=0;i<n;i++){
		if(i>0 && arr[i] == arr[i-1]) continue;

		int j = i+1;
		int k = n-1;

		while(j<k){
			int sum = arr[i]+arr[j]+arr[k];
			if(sum > K) k--;
			else if(sum < K) j++;
			else{
				vector<int> temp ={arr[i],arr[j],arr[k]};
				ans.push_back(temp);
				j++;
				k--;

				while(j<k && arr[j]==arr[j-1]) j++;
				while(j<k && arr[k]==arr[k+1]) k--;
			}
		}
	}
	return ans;
	//TC = O(N^2) + O(NlogN);
	//SC = O(no of triplets);

}