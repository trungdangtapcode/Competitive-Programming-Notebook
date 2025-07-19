#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int maxN = 5e5+5;
int n, deg[maxN], ch[maxN];
ii a[maxN];
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a+1, a+n+1);
	ch[1] = 1;
	for (int i = 2; i <= n; i++){
		if (a[i]==a[i-1]) ch[i] = 0;
		else ch[i] = 1;
	}
	deque<int> d;
	for (int i = 1; i <= n; i++) if (ch[i]){
		while (d.size()&&a[i].second-a[d.back()].second>=a[i].first-a[d.back()].first){
			deg[d.back()]++;
//			cout << i << " -> " << d.back() << "\n";
			d.pop_back();
		}
		d.push_back(i);
	}
	d.clear();
	for (int i = n; i >= 1; i--)if (ch[i]){
		while (d.size()&&a[i].second-a[d.back()].second>=-a[i].first+a[d.back()].first){
			deg[d.back()]++;
//			cout << i << " -> " << d.back() << "\n";
			d.pop_back();
		}
		d.push_back(i);
	}
	int res = 0;
	for (int i = 1; i <= n; i++)if (ch[i]){
//		cout << deg[i] << "\n";
		res += deg[i]==0;
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

