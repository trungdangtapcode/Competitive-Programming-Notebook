#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9, maxN = 2e5+5;
int nxt[maxN];

void solve() {
	string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    for (int i = 0; i <= n+1; i++) nxt[i] = 0;
    for (int i = n; i >= 1; i--){
    	if (s[i]=='p'){
    		nxt[i] = 1;
		} else {
			if (s[i]=='t') nxt[i] = 0;
			else nxt[i] = nxt[i+1];
		}
	}
	int res = n;
    for (int i = 1; i < n; i++){
    	if (s[i]=='p'&&s[i+1]=='t'&&nxt[i+2]==1) res--;
	}
	cout << res << "\n";
    
    return;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
    int t;
    cin >> t;
    while (t--)
    solve();
    
    return 0;
}
