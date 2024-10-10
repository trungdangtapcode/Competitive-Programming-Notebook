#include<bits/stdc++.h>

using namespace std;
#define int long long
int n;
void solve(){
	cin >> n;
	int win = 0, lose = 0;
	for (int i = 0; (1<<i) <= n; i++){
		int seg = 1<<i, cnt = n/seg, odd = (cnt+1)/2, even = cnt-odd;
		if (i%2){
			int cur = 2*odd*cnt - odd*odd;
			win += cur;
		} else {
			int cur = odd*odd;
			lose += cur;
		}
	}
	cout << win << "\n";
	cout << n*n-win-lose << "\n";
	cout << lose << "\n";
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

