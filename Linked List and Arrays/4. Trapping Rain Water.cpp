#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    
    //Brute
    long waterTrapped = 0;
    
    for(int i=0;i<n;i++){
        int j = i;
        long leftmax = 0,rightmax = 0;

        while(j>=0){
            leftmax = max(leftmax,arr[j]);
            j--;
        }

        j = i;

        while(j<n){
            rightmax = max(rightmax,arr[j]);
            j++;
        }

        waterTrapped += min(leftmax,rightmax) - arr[i];
    }

    return waterTrapped;
    //TC = O(N*N);
    //SC = O(1);

    //Better 
    long prefMax[n];
    long sufixMax[n];

    prefMax[0] = arr[0];
    for(int i=1;i<n;i++){
        prefMax[i] = max(prefMax[i-1],arr[i]);
    }

    sufixMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        sufixMax[i] = max(sufixMax[i+1],arr[i]);
    }

    long waterTrapped = 0;
    for(int i=0;i<n;i++){
        waterTrapped += min(prefMax[i],sufixMax[i]) - arr[i];
    }

    return waterTrapped;
    //TC = O(N) + O(N) + O(N);
    //SC = O(N) + O(N);

    //Optimal
    long res = 0;
    long maxLeft = 0, maxRight = 0;
    int left = 0, right = n-1;

    while(left<=right){
        if(arr[left] <= arr[right]){
            if(maxLeft<=arr[left]){
                maxLeft = max(maxLeft,arr[left]);
            }
            else{
                res += maxLeft - arr[left];
            }
            left++;
        }
        else{
            if(maxRight <= arr[right]){
                maxRight = max(maxRight,arr[right]);
            }
            else{
                res += maxRight - arr[right];
            }
            right--;
        }
    }
    return res;
    //TC = O(N);
    //SC = O(1);
}