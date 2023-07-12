#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack<long long> st;
	long long mini;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			while(st.empty() == false) st.pop();
			mini = -1;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			long long val = num;
			if(st.empty()){
				mini = val;
				st.push(val);
			}
			else{
				if(val < mini){
					st.push(2*val - mini);
					mini = val;
				}
				else{
					st.push(val);
				}
			}
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty()) return -1;
			long long element = st.top();
			st.pop();

			if(element < mini){
				int mini2 = mini;
				mini = 2*mini - element;
				return mini2;
			}

			return element;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty()) return -1;

			long long element = st.top();
			if(element < mini) return mini;
			return element;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.empty()) return -1;
			return mini;
		}
};