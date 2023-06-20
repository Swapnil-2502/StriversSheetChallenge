#include<set>
int removeDuplicates(vector<int> &arr, int n) {
	
	//Brute
	set<int> st;

	for(int i=0;i<n;i++){
		st.insert(arr[i]);
	}

	return st.size();
	//TC = O(N) + O(logN);
	//SC = O(no of unique elements);

	//Optimal 
	int i=0;
	for(int j=1;j<n;j++){
		if(arr[i] != arr[j]){
			i++;
			arr[i] = arr[j];
		}
	}

	return i+1;
	//TC = O(N);
	//SC = O(1);

}