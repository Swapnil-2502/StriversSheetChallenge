#include<bits/stdc++.h>
int largestRectangle(vector < int > & heights) {
  
  //brute
  int n = heights.size();
  int maxArea = 0;

  for(int i=0;i<n;i++){
    int minHeight = INT_MAX;

    for(int j=i;j<n;j++){
      minHeight = min(minHeight,heights[j]);
      maxArea = max(maxArea, minHeight*(j-i+1)); 
    }
  }

  return maxArea;
  //TC = O(N*N);
  //SC = O(1);

  // //Optimal Sol 1;

  int n = heights.size();
  int leftsmall[n], rightsmall[n];
  stack<int> st;

  for(int i=0;i<n;i++){
    while(!st.empty() && heights[st.top()] >= heights[i]){
      st.pop();
    }

    if(st.empty()){
      leftsmall[i] = 0;
    }
    else{
      leftsmall[i] = st.top() + 1;
    }

    st.push(i);

  }

  while(!st.empty()) st.pop();

  for(int i=n-1;i>=0;i--){
    while(!st.empty() && heights[st.top()] >= heights[i]){
      st.pop();
    }

    if(st.empty()){
      rightsmall[i] = n-1;
    }
    else{
      rightsmall[i] = st.top() - 1;
    }

    st.push(i);
  }

  int maxA = 0;
  for (int i = 0; i < n; i++) {
    maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
  }

  return maxA;
  //TC = O(N);
  //SC = O(3N);

  //Optimal Sol 2;

  int n = heights.size();
  stack<int> st;
  int maxArea = 0;

  for(int i=0;i<=n;i++){
    while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
      int height = heights[st.top()];
      st.pop();
      int width;

      if(st.empty()) width = i;
      else{
        width = i - st.top() - 1;
      }

      maxArea = max(maxArea , height*width);
    }
    st.push(i);
  }

  return maxArea;

  //TC = O(N) + O(N);
  //SC = O(N);
}