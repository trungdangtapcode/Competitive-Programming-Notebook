#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxN = 5e3+5;
int n, k, a[maxN];
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	long long res = LLONG_MAX;

    for (int s = 1; s <= 5; ++s) {
        ll sm = 0;
        int cur = s;
        for (int i = 1; i <= n; ++i) {
            sm += abs(a[i] - s - i*k + k);
        }
        res = min(res, sm);
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

