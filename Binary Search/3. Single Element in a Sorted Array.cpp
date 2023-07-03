int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	//Lucky Number is first
	if(arr[0] != arr[1]) return arr[0];

	//Lucky Number is last
	if(arr[n-1] != arr[n-2]) return arr[n-1];

	//Lucky number in middle
	for(int i=1;i<arr.size()-1;i++){
		if(arr[i] != arr[i-1] && arr[i]!=arr[i+1]) return arr[i];
	}

	//TC = O(N);
	//SC = O(1);
}