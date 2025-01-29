#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 1e5+5;
int n, l, r, a[maxN];

void solve(){
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector<int> vl, vm, vr;
	for (int i = 1; i < l; i++) vl.push_back(a[i]);
	for (int i = l; i <= r; i++) vm.push_back(a[i]);
	for (int i = r+1; i <= n; i++) vr.push_back(a[i]);
	sort(vl.begin(),vl.end());
	sort(vr.begin(),vr.end());
	sort(vm.begin(),vm.end());
	reverse(vm.begin(),vm.end());
	int res1 = 0, res2 = 0;
	for (int i = 0; i < vm.size(); i++) res1 += min(vl.size()>i?vl[i]:(int)1e9,vm[i]);
	for (int i = 0; i < vm.size(); i++) res2 += min(vr.size()>i?vr[i]:(int)1e9,vm[i]);
	cout << min(res1,res2) << "\n";
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

