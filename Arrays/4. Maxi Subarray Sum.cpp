#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{

    //Optimal
    //Kadan's Algorithm
    long long ans = 0;
    long long sum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];

        ans = max(ans,sum);

        if(sum < 0) sum = 0;
    }
    return ans;
    // // //TC = O(N);
    // // //SC = O(1);
    

    // //Better
    // long long ans = INT_MIN;
    // for(int i=0;i<n;i++){
    //     long long sum = 0;
    //     for(int j=i;j<n;j++){
    //         sum += arr[j];
    //         ans = max(ans,sum);
    //     }
    // }
    // if(ans < 0) return 0;
    // return ans;
    // // //TC = O(N^2);
    // // //SC = O(1);/


    // //Brute
    // long long ans = INT_MIN;

    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         long long sum = arr[j];
    //         for(int k=i;k<j;k++){
    //             sum += arr[k];
    //         }
    //         ans = max(ans,sum);
    //     }
    // }
    // if(ans < 0) return 0;
    // return ans;
    // //TC = O(N^3);
    // //SC = O(1);
}