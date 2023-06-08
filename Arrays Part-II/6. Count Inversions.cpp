#include <bits/stdc++.h> 

long long getInversions(long long *arr, long long n){
    
    //Brute
    int CountInversions = 0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i] > arr[j]) CountInversions++;
        }
    }

    return CountInversions;
    //TC = O(N*N);
    //SC = O(1);
}