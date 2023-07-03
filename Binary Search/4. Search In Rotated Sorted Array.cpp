#include<bits/stdc++.h>
int search(int* arr, int n, int key) {
    
    //Brute
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]] = i;
    }

    if(mp.find(key) != mp.end()) return mp[key];
    return -1;
    //We can also use liner search where SC = O(1)
    //TC = O(N);
    //SC = O(N);

    //But we need to do using BS
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = (low + high)/2;

        if(arr[mid] == key) return mid;

        if(arr[low]<=arr[mid]){
            if(arr[low]<=key && key<=arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            if(arr[mid]<=key && key<=arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
    //TC = O(logN);
    //SC = O(1);
}