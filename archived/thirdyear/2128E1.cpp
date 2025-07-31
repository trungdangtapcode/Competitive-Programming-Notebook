#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxN = 5e5+5;
int n, a[maxN], k, pref[maxN];
typedef pair<int,int> ii;
ii check(int x){
	for (int i = 1; i <= n; i++){
		pref[i] = pref[i-1] + (a[i]>=x?1:-1);
	}
	int mmin = 1e9, mmin_j = -1;
	for (int i = 1, j = 0; i <= n; i++){
		if (i>=k){
			if (mmin>pref[j]){
				mmin = pref[j];
				mmin_j = j+1;
			}
			j++;
		}
		if (pref[i]>=mmin){
			return {mmin_j, i};
		}
	}
	return {-1,-1};
}

void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = -1, resl = 0, resr = 0;
	for (int ll = 0, rr = n; ll <= rr;){
		int mm = ll+rr>>1;
		auto it = check(mm);
		int u = it.first, v = it.second;
		if (u!=-1){
			res = mm;
			resl = u;
			resr = v;
			ll = mm+1;
		} else {
			rr = mm-1;
		}
	}
	cout << res << " " << resl << " " << resr << "\n";
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

