#include <bits/stdc++.h> 

void f(int index,vector<string> &ans, string t,string &s, vector<string> &dictionary,
unordered_map<string,int> &mp){

    //Base Case
    if(index == s.length()){
        ans.push_back(t);
        return ;
    }

    string a;
    for(int i=index;i<s.length();i++){
        a+=s[i];

        if(mp.find(a)!=mp.end()){
            if(t.length() == 0) f(i+1,ans,t+a,s,dictionary,mp);

            else f(i+1,ans,t+" "+a,s,dictionary,mp);
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    
    unordered_map<string,int> mp;

    for(auto it : dictionary){
        mp[it]++;
    }

    string t;
    vector<string>ans;

    f(0,ans,t,s,dictionary,mp);

    return ans;
    //TC = O()
}