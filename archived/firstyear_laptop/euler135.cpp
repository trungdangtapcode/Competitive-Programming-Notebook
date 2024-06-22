#include<bits/stdc++.h>

using namespace std;
const int maxN = 8e6+5;
int n, f[maxN];
void solve(){
	cin >> n;
	cout << f[n] << "\n";	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	
	//(u+2d)^2 - (u+d)^2 - u^2 = -u^2+2ud+3d^2 = (u+d)(3d-u), d>0
	for (int u = 1; u <= 8e6; u++){
		for (int d = (u+2)/3; d <= 8e6; d++){
			if (1ll*(u+d)*(3*d-u)>8e6) break;
			f[(u+d)*(3*d-u)]++;
		}
	}
	
	
	int t; cin >> t;
	while (t--)
	solve();
}

