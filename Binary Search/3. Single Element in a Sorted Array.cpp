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

    //Binary Search
	int low = 0;
	int high = n-2;

	while(low <= high){
		
		int mid=(low + high)/2;

		if(mid %2 == 0){
			if(arr[mid] != arr[mid+1]){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
		else{
			if(arr[mid] == arr[mid+1]){
				high = mid-1;
			}
			else{
				low = mid+1;
			}
		}
	}
	return arr[low];
	//TC = O(N);
	//SC = O(1);
}