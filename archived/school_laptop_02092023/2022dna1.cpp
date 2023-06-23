#include<bits/stdc++.h>

using namespace std;
string s, t;
int n, m, prv1[1005][30], prv2[1005][30], lcs[1005][1005], cnt[1005][1005];
const int p = 20030101;

int main(){
	
	int test; cin >> test;
	while (test--){
		memset(cnt,0,sizeof(cnt));
		memset(lcs,0,sizeof(lcs));
		cin >> s >> t;
		s = s+"@"; t = t+"@";
		n = s.length();
		m = t.length();
		s = "#" + s;
		t = "#" + t;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
				if (s[i]==t[j]) lcs[i][j] = max(lcs[i][j],lcs[i-1][j-1]+1);
			}
		}
		for (int i = 1; i <= n; i++) for (int j = 'a'; j <= 'z'; j++){
			if (s[i]==j) prv1[i][j-'a'] = i;
			else prv1[i][j-'a'] = prv1[i-1][j-'a'];
		}
		for (int i = 1; i <= m; i++) for (int j = 'a'; j <= 'z'; j++){
			if (t[i]==j) prv2[i][j-'a'] = i;
			else prv2[i][j-'a'] = prv2[i-1][j-'a'];
		}
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				for (int k = 'a'; k <= 'z'; k++){
					if (lcs[i][j]==1&&s[i]==t[j]) cnt[i][j] = 1;
					int x = prv1[i-1][k-'a'], y = prv2[j-1][k-'a'];
					if (x==0||y==0) continue;
					if (lcs[x][y]!=lcs[i][j]-1) continue;
					cnt[i][j] = (cnt[i][j]+cnt[x][y])%p;
				}
			}
		}
		cout << lcs[n][m]-1 << " " << (lcs[n][m]==1?0:cnt[n][m]) << "\n";
	}
	
	return 0;
}
