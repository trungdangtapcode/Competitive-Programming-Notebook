#include <bits/stdc++.h>

using namespace std;
string t, s[200005], tt, st[200005];
int prv[200005][105], nxt[200005][105];
int n;
int cnt1[25], cnt2[25];
long long int res = 0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> t >> n;
	tt = t;
	reverse(tt.begin(),tt.end());
	for (int i = 0; i < n; i++){
		cin >> s[i];
		st[i] = s[i];
		reverse(st[i].begin(),st[i].end());
	}
	
	for (int i = 0; i < n; i++){
		s[i] = t + "#" + s[i];
		int l = s[i].length(); //
		prv[i][0] = -1;
		for (int j = 1, k = -1; j < l; j++){
			k = prv[i][j-1];
			while (k >= 0 && s[i][k+1]!=s[i][j]) k = prv[i][k];
			if (s[i][k+1]==s[i][j]) prv[i][j] = k+1;
			else prv[i][j] = -1;
			if (prv[i][j]==t.length()-1&&j>=t.length()) res+=2*n; //
		}
		st[i] = tt + "#" + st[i];
		nxt[i][0] = -1;
		for (int j = 1, k = -1; j < l; j++){
			k = nxt[i][j-1];
			while (k >= 0 && st[i][k+1]!=st[i][j]) k = nxt[i][k];
			if (st[i][k+1]==st[i][j]) nxt[i][j] = k+1;
			else nxt[i][j] = -1;
//			if (l>83) cout << j << " " << nxt[i][j] << endl;
		} 
	}
//	cout << res << endl;
	for (int i = 0, k = -1; i < n; i++){
		k = prv[i][s[i].length()-1];
		while (k>=0) cnt1[k+1]++, k = prv[i][k];
		k = nxt[i][st[i].length()-1]; //
		while (k>=0) cnt2[k+1]++, k = nxt[i][k];
	}
//	res = 0;
	for (int i = 1; i < t.length(); i++){
		res += (long long int)cnt1[i]*cnt2[t.length()-i];
	}
	cout << res << '\n';
	
//	for (int i = 0; i < n; i++){
//		cout << st[i] << " with length " << st[i].length() << endl;
//		for (int j = 0; j < s[i].length(); j++) cout << nxt[i][j] << " ";
//		cout << endl;
//	}
//	for (int i = 1; i <= t.length(); i++){
//		cout << "cnt1["<<i << "] = " << cnt1[i] << "   cnt2[" << i << "] = " << cnt2[i] << endl; 
//	}
	
	return 0;
}


//	nxt[i][l-1] = l;
//		for (int j = l-2, k = -1; j >= 0; j--){
//			k = nxt[i][j+1];
//			while (k < l && s[i][k-1]!=s[i][j]) k = nxt[i][k];
//			if (s[i][k-1]==s[i][j]) nxt[i][j] = k-1;
//			else nxt[i][j] = l;
//		}
