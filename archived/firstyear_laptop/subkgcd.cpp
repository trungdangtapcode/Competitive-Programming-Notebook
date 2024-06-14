#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;
int n, a[maxN], pref[maxN], k;
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		pref[a[i]]++;
	}
	for (int i = 1; i <= 1e6; i++){
		pref[i] += pref[i-1];
	}
	int res = 1;
	for (int d = 1e6; d > 1; d--){
//		cout << d << "\n";
		bool flag = 1;
		for (int x = 0; x <= 1e6; x += d){
			if (pref[min((int)1e6,x+d-1)]-pref[min((int)1e6,x+k)]>0){
				flag = 0;
				break;
			}
		}
		if (flag){
			res = d;
			break;
		}
	}
	cout << res;
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

