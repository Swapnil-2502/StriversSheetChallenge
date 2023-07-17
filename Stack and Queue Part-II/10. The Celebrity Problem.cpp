#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	
	stack<int> st;

	//First put all persons in the stack;

	for(int i=0;i<=n-1;i++){
		st.push(i);
	}

	while(st.size()>1){
		int A = st.top();
		st.pop();
		int B = st.top();
		st.pop();

		if(knows(A,B)) st.push(B);
		else st.push(A);
	}

	//Now only last person is left but still there is the posibility he cannot
	//be a celebrity

	int CanbeCelebrity = st.top();

	for(int i=0;i<n;i++){
		if(knows(CanbeCelebrity,i)) return -1;

		if(i!=CanbeCelebrity && !knows(i,CanbeCelebrity)) return -1;
	}

	return CanbeCelebrity;


	//TC = O(N) + O(N);
	//SC = O(N);
}