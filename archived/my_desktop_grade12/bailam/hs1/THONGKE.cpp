#include<bits/stdc++.h>

using namespace std;
int n;
map<int,int> m;
int main(){
	freopen("THONGKE.INP","r",stdin);
	freopen("THONGKE.OUT","w",stdout);
	cin >> n;
	for (int i = 0,a; i < n; i++){
		cin >> a;
		m[a]++;
	};
	int res = 0;
	for (auto it: m){
		res = max(res,it.second);
	}
	cout << m.size() << "\n" << res;
	return 0;
}
