#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	//Base Cases
	if(n==1) return "1";
	if(n==2) return "11";
	string s = "11";

	for(int i=3;i<=n;i++){
		string t = "";
		s+='&';
		int count = 1;

		for(int j=1;j<s.length();j++){
			if(s[j]!=s[j-1]){
				t = t + to_string(count);
				t = t + s[j-1];
				count = 1;
			}
			else count++;

		}
		s=t;
	}
	return s;
	//TC = O(n*len);
	//SC = O(1);
}