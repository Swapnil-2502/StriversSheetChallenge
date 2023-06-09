#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{   

    //Optimal (Extended Boyer Moore’s Voting Algorithm)
    int n = arr.size();
    int reqFreq = int(n/3) + 1;

    int count1=0, count2=0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for(int i=0;i<n;i++){
        
        if(count1 == 0 && arr[i]!=ele2){
            count1 = 1;
            ele1 = arr[i];
        }
        else if(count2 == 0 && arr[i]!=ele1){
            count2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) count1++;
        else if(arr[i] == ele2) count2++;
        else {
            count1--;count2--;
        }
    }

    vector<int> ans;

    int c1 = 0;
    int c2 = 0;

    for(int i=0;i<n;i++){
        if(arr[i] == ele1) c1++;
        if(arr[i] == ele2) c2++;
    }

    if(c1 >= reqFreq) ans.push_back(ele1);
    if(c2 >= reqFreq) ans.push_back(ele2);

    return ans;


    // //Better (Hashing)
    // int n = arr.size();
    // int freqReq = int(n/3) + 1;

    // map<int,int> mp;
    // vector<int> ans;
    
    // for(int i=0;i<n;i++){
        
    //     mp[arr[i]]++;

    //     if(mp[arr[i]] == freqReq) ans.push_back(arr[i]);

    //     if(ans.size() == 2) break;
    // }
    // return ans;
    // //TC = O(NlogN);
    // //SC = O(N);
    
    // //Brute
    // int n = arr.size();
    // vector<int> ans;
    // for(int i=0;i<n;i++){

    //     if(ans.empty() || ans[0] != arr[i]){
    //         int count=0;
    //         for(int j=0;j<n;j++){
    //             if(arr[i] == arr[j]) count++;
    //         }

    //         if(count > (n/3)) ans.push_back(arr[i]);
    //     }
        
    //     if(ans.size() == 2) break;
    // }
    // return ans;
    // //TC = O(N*N);
    // //SC = O(1);

}