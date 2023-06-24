#include<bits/stdc++.h>

using namespace std;
int n;
map<int,int> m;
int main(){
	freopen("CAPSO.INP","r",stdin);
	freopen("CAPSO.OUT","w",stdout);
	long long int res = 0;
	cin >> n;
	for (int i = 0,a; i < n; i++){
		cin >> a;
		res += m.count(-a);
		m[a]++;
	};
	cout << res;
	return 0;
}
