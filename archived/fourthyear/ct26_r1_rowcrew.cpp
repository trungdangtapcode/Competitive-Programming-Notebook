#include<bits/stdc++.h>

using namespace std;
const int N = 2e5+5;
int n, s, d, a[N], taken[N];

void solve(){
	cin >> n >> s >> d;
//	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	int l = 0, r = 0, res = 0;
	taken[0] = 1;
	multiset<int> ms;
	for (int i = 1; i <= n; i++){
		if (taken[i]) continue;
		int ar = d+a[i], al = max(s-a[i],a[i]);
		while (r<n&&a[r+1]<=ar){
			r++;
			if (r>=l&&!taken[r]) ms.insert(r);
		}
		
//		while (l<n&&a[l+1]<al||l<=i+1){
//			if (r>=l&&!taken[l]) ms.erase(ms.find(l));
//			l++;
//		}
		while (l <= n && (a[l] < al || l <= i)){
		    if (l <= r && !taken[l]){
		        auto it = ms.find(l);
		        if (it != ms.end()) ms.erase(it);
		    }
		    l++;
		}
		
		while (l>i+1&&a[l-1]>=al){
			l--;
			if (r>=l&&!taken[l]) ms.insert(l);
		}
//		l = max(l, i);
		if (!ms.empty()){
//			cout << l << " " << r << ": " << ms.size()<< "\n";
			auto it = ms.begin();
			taken[*it] = true;
			ms.erase(it);
			taken[i] = true;
			if (ms.count(i)) ms.erase(ms.find(i));
			res++;
		}
	}
	cout << res;
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

