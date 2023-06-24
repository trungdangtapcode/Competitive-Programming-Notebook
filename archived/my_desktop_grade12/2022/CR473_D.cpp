#include<bits/stdc++.h>

using namespace std;
set<int> s;
bool check[2000005];
int n, spf[2000005];
void updt(int x){
	if (check[x]) return;
	for (int i = x; i <= 2e6; i+=x){
		if (!check[i]) s.erase(i);
		check[i] = true;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 2; i <= 2e6; i++) s.insert(i);
	for (int i = 1; i <= 2e6; i++) spf[i] = i;
	for (int i = 2; i*i <= 2e6; i++) if (spf[i]==i) for (int j = i*i; j <= 2e6; j+=i) spf[j] = i;
	
	cin >> n;
	for (int i = 1, x, a, greater = false, res; i <= n; i++){
		cin >> x;
		if (greater) res = *s.begin(); else res = *s.lower_bound(x);
		if (res>x) greater = true;
		cout << res << " ";
		while (res>1){
			int tmp = spf[res];
			while (res%tmp==0) res /= tmp;
			updt(tmp);
		}
	}
	
	return 0;
}
