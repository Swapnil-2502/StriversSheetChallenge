#include<bits/stdc++.h>

void f(int index, string &s,vector<string> &ds){

    //Base Case
    if(index == s.size()){
        ds.push_back(s);
        return;
    }

    for(int i=index;i<s.size();i++){
        swap(s[index],s[i]);
        f(index+1,s,ds);
        swap(s[index],s[i]);
    }
}


string kthPermutation(int n, int k) {
    
    vector<string> ds;

    string s;

    for(int i=1;i<=n;i++){
        s.push_back(i + '0');
    }

    f(0,s,ds);

    sort(ds.begin(),ds.end());

    auto it = ds.begin() + (k-1);
    return *it;

    //TC = O(N! * N) +O(N! Log N!)
    //SC = O(N);

    int fact = 1;
    vector < int > numbers;
    for (int i = 1; i < n; i++) {
    fact = fact * i;
    numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans = "";
    k = k - 1;
    while (true) {
    ans = ans + to_string(numbers[k / fact]);
    numbers.erase(numbers.begin() + k / fact);
    if (numbers.size() == 0) {
        break;
    }

    k = k % fact;
    fact = fact / numbers.size();
    }
    return ans;

    //TC = O(N) * O(N) = O(N^2)
    //SC = O(N)
    
}
