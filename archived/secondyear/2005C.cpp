#include<bits/stdc++.h>

using namespace std;
const int maxN = 1005;
const char name[] = {'n','a','r','e','k'};
int n, m, f[maxN][5];
string s[maxN];
void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
//		s = ' ' + s;
	}
	set<char> st;
	for (char c: name) st.insert(c);
	for (int i = 0; i <= n; i++) for (int j = 0; j < 5; j++) f[i][j] = -1e9;
	f[0][4] = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 5; j++){
			int nj = j, bonus = 0;
			for (char c: s[i]){
				if (c==name[(nj+1)%5]){
					nj = (nj+1)%5;
					if (nj==4) bonus += 10;
				}
				bonus -= st.count(c);
			}
			f[i][j] = max(f[i-1][j],f[i][j]);
			f[i][nj] = max(f[i-1][j]+bonus,f[i][nj]);
		}
	}
	cout << *max_element(f[n],f[n]+5) << "\n";
//	exit(0);
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

