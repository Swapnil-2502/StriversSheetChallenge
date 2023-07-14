#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    
    int n = price.size();

    vector<int> ans(n,1);

    stack<int> st; //{element,index};

    for(int i=0;i<n;i++){

        while(!st.empty() && price[i]>=price[st.top()]){
            st.pop();
        }

        ans[i] = (st.empty())? i+1: i-st.top();

        st.push(i);
            
    }
    return ans;

    //TC = O(N);
    //SC = O(N);
}