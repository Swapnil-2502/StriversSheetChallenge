#include <bits/stdc++.h> 
struct job{
    int deadline;
    int profit;
};

bool comp(job a , job b){
    return (a.profit > b.profit);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    struct job arr[n];

    for(int i=0;i<n;i++){
        arr[i].deadline = jobs[i][0];
        arr[i].profit = jobs[i][1];
    }

    sort(arr,arr+n,comp);

    int max_deadline = arr[0].deadline;

    for(int i=0;i<n;i++){
        max_deadline = max(max_deadline,arr[i].deadline);
    }

    vector<int> seq(max_deadline+1,-1);

    int profit = 0;
    
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline;j>0;j--){
            if(seq[j] == -1){
                seq[j] = i;
                profit += arr[i].profit;
                break;
            }
        }
    }

    return profit;
    //TC = O(N) + O(N*max(deadline));
    //SC = O(N);
}
