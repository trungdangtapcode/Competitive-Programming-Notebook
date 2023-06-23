#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, c;
string s;

main(){
	freopen("input.txt","r",stdin);
	
	cin >> n >> c >> s;
	s = "#" + s + "#";
	int cur = 0, cntA = 0, cntB = 0, res = 0;
	for (int i = 1, j = 0; i <= n; i++){
		while (j<=n&&cur<=c){
			j++;
			if (s[j]=='b') cntB++, cur += cntA;
			if (s[j]=='a') cntA++;
		}
		if (s[j]=='b') cntB--, cur -= cntA;
		if (s[j]=='a') cntA--;
		j--;
		if (cur<=c) res = max(res,j-i+1);
		if (s[i]=='a') cntA--, cur -= cntB;
		if (s[i]=='b') cntB--;
	}
	cout << res;
	
	
	return 0;
}
