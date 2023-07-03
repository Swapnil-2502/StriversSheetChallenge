double median(vector<int>& a, vector<int>& b) {
	
	// int n = a.size();
	// int m = b.size();

	//Naive Approach
	vector<int> c;

	int i=0,j=0;
	while(i<n && j<m){
		if(a[i]<=b[j]){
			c.push_back(a[i]);
			i++;
		}
		else{
			c.push_back(b[j]);
			j++;
		}
	}

	while(i<n)c.push_back(a[i++]);
	while(j<m) c.push_back(b[j++]);

	n = n+m;
	
	if(n%2 != 0){
		return c[(n+1)/2 - 1];
	}
	else{
		return ((double)c[(n/2) -1] + (double)c[n/2])/2;
	}
	//TC = O(N+M);
	//SC = O(N+M);

	//Using Binary Search
	if(a.size()>b.size()) return median(b,a);
	
	int n = a.size();
	int m = b.size();

	int low = 0, high = m , medianPos = ((n+m)+1)/2;

	while(low <= high){
		int cut1 = (low+high) >> 1;
		int cut2 = medianPos - cut1;

		int l1 = (cut1 == 0)? INT_MIN:a[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN:b[cut2-1];
        int r1 = (cut1 == n)? INT_MAX:a[cut1];
        int r2 = (cut2 == m)? INT_MAX:b[cut2];


		if(l1<=r2 && l2<=r1){
			if((m+n)%2 != 0){
				return max(l1,l2);
			}
			else{
				return (max(l1,l2) + min(r1,r2))/2.0;
			}
		}
		else if(l1 > r2) high = cut1-1;
		else low = cut1 + 1;
	}
	//TC = O(log(min(m,n)))
	//SC = O(1)
	
}