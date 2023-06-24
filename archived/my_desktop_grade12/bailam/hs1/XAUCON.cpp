#include<bits/stdc++.h>

using namespace std;
int k, n, m;
string s;

int main(){
	freopen("XAUCON.INP","r",stdin);
	freopen("XAUCON.OUT","w",stdout);
	
	cin >> s >> n >> m;
	k = s.length();
	
	int res = 1e9;
	for (int i = 0, j = 0, n0 = 0, m0 = 0; i < k; i++){
		while (j<k&&(n0<n||m0<m)) if (s[j++]=='A') n0++; else m0++;
		if (j==k&&(n0<n||m0<m)) break;
		res = min(res,j-i); //j - i = n0 + m0
		if (s[i]=='A') n0--; else m0--;
	}
	cout << (res<1e9?res:-1);
	
	return 0;
}
