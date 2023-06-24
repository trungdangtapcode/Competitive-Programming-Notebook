#include<bits/stdc++.h>

using namespace std;
int n;
vector<pair<int,int>> a;

int main(){
	freopen("LICHHOP.INP","r",stdin);
	freopen("LICHHOP.OUT","w",stdout);
	
	cin >> n;
	a.assign(n,pair<int,int>());
	for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
	sort(a.begin(),a.end());
	int res = 0;
	for (int i = 0, last = -1; i < n; i++){
		int u = a[i].second, v = a[i].first;
		if (last<=u){
			res++;
			last = v;
		};
	}
	cout << res;
	
	return 0;
}
