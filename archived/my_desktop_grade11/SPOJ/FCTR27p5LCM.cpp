#include <bits/stdc++.h>

using namespace std;

int n, a, b, spf[1000006], res;
//map<int,int> m;
vector<int> m;//(1000006);
const int p = 1e9+7;
void sang(int x){
	while (x>1){
		m[spf[x]]++;
		x /= spf[x];
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 1; i <= 1e6; i++) spf[i] = i;
	for (int i = 2; i <= 1e6; i++) if (spf[i]==i){
		if (i*i > 1e6) break;
		for (int j = i*i; j <= 1e6; j += i) spf[j] = i;
	}
	
	int t; cin >> t;
	while (t--){
		cin >> a >> b;
		m.assign(b+1,0);
		for (int i = a; i <= b; i++){
			sang(i);
		}
		res = 1;
		for (auto it: m){
//			res = 1ll*res*(2*it.second+1)%p;
			res = 1ll*res*(2*it+1)%p;
		}
		cout << res << '\n';
	}
	return 0;
}
