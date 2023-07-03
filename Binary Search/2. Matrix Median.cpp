#include <bits/stdc++.h>

int CountLessEqual(vector<int> row, int mid){
    int l = 0, h=row.size()-1;

    while(l<=h){
        int md = (l+h) >> 1;

        if(row[md] <= mid){
            l = md + 1;
        }
        else{
            h = md - 1;
        }
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{   
    int n = matrix.size();
    int m = matrix[0].size();

    //Brute    
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp.push_back(matrix[i][j]);
        }
    }

    sort(temp.begin(),temp.end());

    int median = (temp.size()/2);
    return temp[median];

    //TC = O(n*m) + O(n*mlogn*m);
    //SC = O(n*m);

    //Optimal
    int low = INT_MAX;
    int high = INT_MIN;
    for(int i=0;i<n;i++){
        low = min(low,matrix[i][0]);
    }
    for(int i=0;i<n;i++){
        high = max(high,matrix[i][m-1]);
    }
    
    while(low<=high){
        int mid = (low+high) >> 1;
        int count = 0;

        for(int i=0;i<n;i++){
            count += CountLessEqual(matrix[i],mid);
        }

        if(count <= (n*m)/2){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
    //TC = O(row*log col);
    //SC = O(1);
}