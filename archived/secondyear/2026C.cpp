#include<bits/stdc++.h>

using namespace std;
const int maxN = 4e5+5;
string s;
int n;
void solve(){
	cin >> n >> s;
	s = " " + s + "0";
	long long res = 1ll*n*(n+1)/2;
	int cnt = 0;
	deque<int> dq;
	for (int i = n; i >= 1; i--){
		if (s[i]=='1'){
			dq.push_front(i);
		} else {
			if (dq.size()) res -= dq.back(), dq.pop_back();
		}
	}
	while (dq.size()){
		dq.pop_front();
		if (dq.size()) res -= dq.back(), dq.pop_back();
	}
	cout << res << "\n";
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

