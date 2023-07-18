#include <bits/stdc++.h>
vector<int> generateLPS(string s){
	int m = s.size();
	int len = 0;

	vector<int> lps(m);
	lps[0] = 0;
	int i = 1;
	while(i<m){
		if(s[i]==s[len]){
			len++;
			lps[i] = len;
			i++;
		}

		else{
			if(len!=0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

int minCharsforPalindrome(string str) {
	// Write your code here.
	
	string rev = str;
	reverse(rev.begin(),rev.end());

	string newstr = str + "$" + rev;

	vector<int> lps = generateLPS(newstr);

	return (str.size()-lps.back());

	//TC = O(N);
	//SC = O(N);
}
