#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
const int maxN = 2e5+5;
int n, a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	deque<ii> d;
	d.push_back({a[1],1});
	for (int i = 2; i <= n; i++){
		int s = a[i], cnt = 1;
		while (d.size()&&d.back().first>=s/cnt){
			s += d.back().first*d.back().second;
			cnt += d.back().second;
			d.pop_back();
		}
		d.push_back({s/cnt,cnt-s%cnt});
		if (s%cnt) d.push_back({s/cnt+1,s%cnt});
	}
	cout << d.back().first-d.front().first << "\n";
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

