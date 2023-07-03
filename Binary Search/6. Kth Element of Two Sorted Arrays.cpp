#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
    
    int count = 0;
    int i=0,j=0;

    while(i<m && j<n){
         
        if(row1[i]<=row2[j]){           
            count++;
            if(count == k) return row1[i];
            i++;
        }
        else{           
            count++;
            if(count == k) return row2[j];
            j++;
        }
    }

    while(i<m){
        count++;
        if(count == k) return row1[i];
        i++;
    }
    while(j<n){
        count++;
        if(count == k) return row2[j];
        j++;
    }
    //TC = O(k);
    //SC = O(1);

    //Using Binary Search
    if(n>m) return ninjaAndLadoos(row2,row1,m,n,k);

    int low = max(0,k-m);
    int high = min(k,n);

    while(low <= high){
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0)? INT_MIN: row1[cut1-1];
        int l2 = (cut2 == 0)? INT_MIN: row2[cut2-1];
        int r1 = (cut1 == n)? INT_MAX: row1[cut1];
        int r2 = (cut2 == m)? INT_MAX: row2[cut2];

        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1 + 1;
    } 
    //TC = Log(min(m,n));
    //SC = O(1);

}