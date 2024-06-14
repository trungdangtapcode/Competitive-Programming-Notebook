#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, k, a[maxN];
void solve(){
	cin >> n >> k;
	bool turn = 0;
	for (int i = 1, p = 1; i <= n; i++){
		a[p] = i;
//		cout << p << " ";
		if (!turn){
			if (p+k>n){
				p++;
				if (p>n) p -= k;
				turn ^= 1;
			} else p += k;
		} else {
			if (p-k<1){
				p++;
				turn ^= 1;
			} else p -= k;
		}
	}
	for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
