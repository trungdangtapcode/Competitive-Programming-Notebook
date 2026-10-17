#include<bits/stdc++.h>

using namespace std;
const int N = 2e6+5;
int n, a[N];
long long s, pref[N];

int check(int d){
	deque<int> dq;
	for (int i = 1, j = 0; i <= n; i++){
		while (dq.size()&&i-dq.front()+1>d){
			dq.pop_front();
		}
		while (dq.size()&&a[dq.back()]<=a[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		
//		cout << i << " " << pref[i]-pref[i-d] << " " << dq.front() << "\n";
		if (i>=d&&pref[i]-pref[i-d]-a[dq.front()]<=s) return 1;
	} 
	return 0;
}

void solve(){
	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) pref[i] = pref[i-1]+a[i];
//	for (int i = 0; i <= n; i++){
//		cout << i << " -> " << check(i) << "\n";
//	}
//	check(5);
	int l = 1, r = n, m, res = 0;
	while (l<=r){
		m = (l+r)/2;
		if (check(m)){
			l = m+1;
			res = m;
		} else r = m-1;
	}
	cout << res << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
//	int t; cin >> t;
//	while (t--)
	solve();
}

