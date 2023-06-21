#include <bits/stdc++.h> 

struct meeting{
    int startTime;
    int endTime;
    int position;
};

bool comparator(struct meeting m1, struct meeting m2){
    if(m1.endTime > m2.endTime) return false;
    else if(m1.endTime < m2.endTime) return true;
    else if(m1.position < m2.position) return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    
    int n = start.size();
    struct meeting meet[n];

    for(int i=0;i<n;i++){
        meet[i].startTime = start[i],
        meet[i].endTime = end[i],
        meet[i].position = i+1;
    }

    sort(meet,meet+n,comparator);

    vector<int> ans;

    int limit = meet[0].endTime;
    ans.push_back(meet[0].position);

    for(int i=1;i<n;i++){
        if(meet[i].startTime > limit){
            limit = meet[i].endTime;
            ans.push_back(meet[i].position);
        }
    }

    return ans;

    //TC = O(N) + O(NlogN) + O(N);
    //SC = O(N);
}