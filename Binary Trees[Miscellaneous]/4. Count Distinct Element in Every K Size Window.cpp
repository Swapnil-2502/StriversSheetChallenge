#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // vector<int> ans;
    // int n = arr.size();
    // for(int i=0;i<n-k+1;i++){
    //     set<int> s;
    //     for(int j = i;j<=i+k-1;j++){
    //         s.insert(arr[j]);
    //     }
    //     ans.push_back(s.size());
    // }
    // return ans;
	// //TC = O(n*k*logk);
    // //SC = O(k);

    vector<int> result;

    unordered_map<int, int> frequencyMap;

    // Count the frequency of each element in the first window

    for (int i = 0; i < k; i++) {

        frequencyMap[arr[i]]++;

    }
    result.push_back(frequencyMap.size());

    for (int i = k; i < arr.size(); i++) {

        frequencyMap[arr[i - k]]--;

        if (frequencyMap[arr[i - k]] == 0) {

            frequencyMap.erase(arr[i - k]);

        }

        frequencyMap[arr[i]]++;

        result.push_back(frequencyMap.size());

    }
    return result;
    //Tc = O(N);
    //SC = O(k);
}
