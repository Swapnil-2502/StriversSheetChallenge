#include <bits/stdc++.h> 

int solve(int index1, int index2, vector<int> &nums){
    int maxi = INT_MIN;

    for(int i=index1;i<=index2;i++){
        maxi = max(maxi,nums[i]);
    }

    return maxi;
}

vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //Brute
    vector<int> ans;
    int n = nums.size();
    for(int i=0;i<=n-k;i++){
        int maxElementinWindow = solve(i,i+k-1,nums);
        ans.push_back(maxElementinWindow);
    }
    return ans;

    //TC = O((N-K)*K);
    //SC = O(N-K);

    //Optimal
    deque<int> dq;
    vector<int> ans;
    int n = nums.size();
    
    for(int i=0;i<n;i++){

        if(!dq.empty() && dq.front() == i-k) dq.pop_front();

        while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

        dq.push_back(i);

        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
    //TC = O(N);
    //SC = O(N-K+1);
}