#include<bits/stdc++.h>

using namespace std;

int n;
bool c[15];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 0; i <= 9; i++) c[i] = 0;
		for (int i = 0, x; i < n; i++){
			cin >> x;
			c[x] = 1;
		}
		int res = 0;
		for (int i = 0; i <= 9; i++) if (!c[i]) res++;
		cout << 3ll*res*(res-1) << "\n";
	}
	return 0;
}
