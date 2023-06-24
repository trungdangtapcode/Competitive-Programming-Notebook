#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int n0, m0;
int x, y;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k;
	n0 = n; m0 = m;
	vector <bool> cntR(n,false); //int: have is True
	vector <bool> cntC(n,false);
	for (int i = 0; i < k; i++){
		cin >> x >> y;
		cntR[x-1] = true; //>0
		cntC[y-1] = true;
	}
	for (int i = 0; i < n; i++) if (!cntR[i]) n0--;
	for (int i = 0; i < m; i++) if (!cntC[i]) m0--;
	cout << (long long int)n0*m0;
	
	return 0;
}

