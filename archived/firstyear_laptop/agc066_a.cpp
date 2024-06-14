#include<bits/stdc++.h>

using namespace std;
const int maxN = 505;
int n, a[maxN][maxN], b[maxN][maxN], d, d2;
int calc(int k){
	int res = 0, kk = (k+d)%d2;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if ((i+j)%2) res += min((a[i][j]-k+2*d2)%d2,(k-a[i][j]+2*d2)%d2);
			else res += min((a[i][j]-kk+2*d2)%d2,(kk-a[i][j]+2*d2)%d2);
//			if ((i+j)%2) cout << min((a[i][j]-k+2*d2)%d2,(k-a[i][j]+2*d2)%d2) << " ";
//			else cout << min((a[i][j]-kk+2*d2)%d2,(kk-a[i][j]+2*d2)%d2) << " ";
		}
//		cout << "\n";
	}
	return res;
}

void solve(){
	cin >> n >> d;
	d2 = d*2;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> b[i][j];
			a[i][j] = b[i][j]%(2*d);
		}
	}
	int res;
//	cout << calc(0)+calc(d) << "\n";
//	return;
	if (calc(0)<=d*n*n/2) res = 0;
	else res = d;
	int ress = (res+d)%d2;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if ((i+j)%2){
				cout << ((a[i][j]-res+2*d2)%d2<=(res-a[i][j]+2*d2)%d2?
					b[i][j]-(a[i][j]-res+2*d2)%d2:
					b[i][j]+(res-a[i][j]+2*d2)%d2) << " ";
			} else {
				cout << ((a[i][j]-ress+2*d2)%d2<=(ress-a[i][j]+2*d2)%d2?
					b[i][j]-(a[i][j]-ress+2*d2)%d2:
					b[i][j]+(ress-a[i][j]+2*d2)%d2) << " ";
			}
		}
		cout << "\n";
	}
//	cout << calc(0) << " " << d2 << "\n";
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

