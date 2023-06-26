#include<bits/stdc++.h>
struct meeting{
    int startTime;
    int endTime;
};
bool comp(struct meeting m1, struct meeting m2){
    if(m1.endTime<m2.endTime) return true;
    else if(m1.endTime>m2.endTime) return false;
    else return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    struct meeting m[n];

    for(int i=0;i<n;i++){
        m[i].startTime = start[i];
        m[i].endTime = finish[i]; 
    }

    sort(m,m+n,comp);

    int count = 1;
    int limit = m[0].endTime;

    for(int i=1;i<n;i++){
        if(m[i].startTime >= limit){
            limit = m[i].endTime;
            count++;
        }
    }
    return count;

    //TC = O(n) + O(nlogn) + O(n) => approx O(nlogn);
    //SC = O(n);

}