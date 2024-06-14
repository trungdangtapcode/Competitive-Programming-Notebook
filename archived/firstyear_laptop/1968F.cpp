#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, q;
int a[maxN], prv[maxN], b[maxN];
vector<int> pos[maxN];
void solve(){
	cin >> n >> q;
	for (int i = 0; i <= n; i++) pos[i].clear();
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) prv[i] = prv[i-1]^a[i];
	
	vector<int> v;
	for (int i = 0; i <= n; i++){
		v.push_back(prv[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for (int i = 0; i <= n; i++) b[i] = lower_bound(v.begin(),v.end(),prv[i])-v.begin();
	for (int i = 0; i <= n; i++) pos[b[i]].push_back(i);
//	for (int i = 0; i <= n; i++) cout << b[i] << " "; cout << "\n";
	while (q--){
		int l, r; cin >> l >> r;
		if (prv[r]==prv[l-1]){
			cout << "YES\n";
			continue;
		} 
		auto it = upper_bound(pos[b[l-1]].begin(),pos[b[l-1]].end(),r);
		if (it==pos[b[l-1]].begin()){
			cout << "NO\n";
			continue;
		}
		it--;
		int pos_r = *it;
//		cout << pos_r << "r\n";
		if (pos_r<l){
			cout << "NO\n";
			continue;
		}	
		
		auto it2 = upper_bound(pos[b[r]].begin(),pos[b[r]].end(),pos_r);
		if (it2==pos[b[r]].begin()){
			cout << "NO\n";
			continue;
		}
		it2--;
		int pos_l = *it2;
		if (pos_l<l){
			cout << "NO\n";
			continue;
		}	
		cout << "YES\n";
		
	}
	cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

