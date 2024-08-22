#include<bits/stdc++.h>

using namespace std;
int n, m;
void solve(){
	cin >> n >> m;
	int x, y;
	for (int i = 0, m = 0; i < n; i++){
		string s; cin >> s;
		int c = 0;
		for (char ch: s) c += ch=='#';
		if (c>m){
			m = c;
			x = i+1;
			int tmp = 0, ptr = 0;
			for (char ch: s){
				tmp += ch=='#';
				ptr++;
				if (2*tmp-1==c){
					y = ptr;
					break;
				}
			}
		}
	}
	cout << x << " " << y << "\n";
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

