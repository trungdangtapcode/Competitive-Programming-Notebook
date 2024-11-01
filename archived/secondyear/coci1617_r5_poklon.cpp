#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, int> iii;
const int maxN = 5e5+5, T = sqrt(maxN);
int n, q, a[maxN], cnt[maxN], res[maxN];
iii qr[maxN];
void solve(){
	cin >> n >> q;
	vector<int> vec;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		vec.push_back(a[i]);
	}
	sort(vec.begin(),vec.end());
	vec.erase(unique(vec.begin(),vec.end()),vec.end());
	for (int i = 1; i <= n; i++) a[i] = lower_bound(vec.begin(),vec.end(),a[i])-vec.begin();
		
	for (int i = 1; i <= q; i++){
		cin >> qr[i].first.first >> qr[i].first.second;
		qr[i].second = i;
	}
	sort(qr+1, qr+q+1, [](iii a, iii b){
		return make_pair(a.first.first/T,a.first.second)
			<make_pair(b.first.first/T,b.first.second);	
	});
	int ll = 1, rr = 0, cur = 0;
	for (int i = 1; i <= q; i++){
		int l = qr[i].first.first, r = qr[i].first.second
		, idx = qr[i].second;
		while (ll>l){
			ll--; 
			if (cnt[a[ll]]==2) cur--;
			cnt[a[ll]]++;
			if (cnt[a[ll]]==2) cur++;
		}
		while (ll<l){
			if (cnt[a[ll]]==2) cur--;
			cnt[a[ll]]--;
			if (cnt[a[ll]]==2) cur++;
			ll++;
		}
		while (rr<r){
			rr++;
			if (cnt[a[rr]]==2) cur--;
			cnt[a[rr]]++;
			if (cnt[a[rr]]==2) cur++;
		}
		while (rr>r){
			if (cnt[a[rr]]==2) cur--;
			cnt[a[rr]]--;
			if (cnt[a[rr]]==2) cur++;
			rr--;
		}
//		cout << ll << " " << rr << " " << cur << "\n";
		res[idx] = cur;
	}
	for (int i = 1; i <= q; i++) cout << res[i] << "\n";
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

