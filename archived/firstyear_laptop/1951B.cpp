#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;
int n, k, a[maxN];
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int avai = 1, x = 0, y = 0;
	for (int i = 1; i <= n; i++){
		if (a[i]>a[k]){
			if (!avai){
				break;
			};
			avai = 0;
		} 
		x = i;
		if (avai) y = i;
	}
//	cout << x << " " << y << "\n";
//	for (int i = max(x+2,k+1); i <= n; i++){
//		if (a[i]<a[k]){
//			cout << max({0,y-k+1, x-k+1,y-1}) << "\n";
//			return;
//		}
//	}
//	cout << max({0,y-k+1, x-1-k+1,min(k-1,x)-(y+1)+1,y-1}) << "\n";
	cout << max(y-1,min(k-1,x)-(y+1)+(y+1!=1)) << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

