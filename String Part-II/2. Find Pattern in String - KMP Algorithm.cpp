// #include <bits/stdc++.h> 
// bool checkPattern(string p, string s, int index){
//     int j = 0;
//     int indexs = index;
//     for(int i=0;i<p.size();i++){
//         if(s[indexs]!=p[j]) return false;

//         indexs++;j++;
//     }
//     return true;
// }

// bool findPattern(string p, string s)
// {
//     //Brute
//     int m = p.length();
//     int n = s.length();

//     for(int i=0;i<=n-m;i++){
        
//         if(checkPattern(p,s,i)) return true;
        
//     }
//     return false;
//     //TC = O((n-m)*m);
//     //SC = O(1);

// }

#include <bits/stdc++.h> 
void lps(string p,vector<int>&temp,int pS)
{
    temp[0]=0;
    int i=0;
    int j=1;
    while(j<pS)
    {
        if(p[i]==p[j])
        {
            i++;
            temp[j]=i;
            j++;
        }
        else
        {
            if(i!=0)
            i=temp[i-1];
            else
            {
                temp[j]=0;
                j++;
            }
        }
    }
}
bool findPattern(string p, string s)
{
    // Write your code here.
    int pS=p.size();
    int sS=s.size();
    vector<int>temp(pS);
    lps(p,temp,pS);
    int i=0;
    int j=0;
    while(j<sS)
    {
        if(s[j]==p[i])
        {
            i++;
            j++;
        }
        if(i==pS)
        return true;
        else if(j<sS && s[j]!=p[i])
        {
            if(i!=0)
            i=temp[i-1];
            else
            j++;
        }
    }
    return false;
}