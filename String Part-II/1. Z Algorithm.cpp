bool checkPattern(string s, string p ,int index){
	int j = 0;
	for(int i=0;i<p.size();i++){
		if(s[index]!=p[j]) return false;

		j++;index++;
	}
	return true;

}
int zAlgorithm(string s, string p, int n, int m)
{	
	//Brute
	int count = 0;

	for(int i=0;i<=n-m;i++){
		if(checkPattern(s,p,i)) count++;
	}

	return count;
	//TC = O((n-m)*m);
	//SC = O(1);

	//Optimal
	
}