#include<bits/stdc++.h>

using namespace std;

int n, m, res;
bool p[25000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	p[0] = p[1] = 1;
	for (int i = 2; i <= n+m; i++) if (!p[i]){
		for (int j = 2*i; j <= n+m; j += i) p[j] = 1;
	}
	int res = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) res += !p[i+j];
	}
	cout << res;
	
	return 0;
}
