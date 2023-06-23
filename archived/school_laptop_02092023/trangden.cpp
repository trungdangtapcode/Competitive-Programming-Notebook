#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int n, x, y;
vector<ii> a;

int main(){
//	freopen(".INP");
	
	cin >> n >> x >> y;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(),a.end());
	
	int res = 1e9;
	for (int i = 0, j = -1, cnt0 = 0, cnt1 = 0; i < n; i++){
		while (j<n-1&&(cnt0<x||cnt1<y)){
			j++;
			if (a[j].second) cnt1++; else cnt0++;
		};
		if (cnt0>=x&&cnt1>=y) res = min(res,a[j].first-a[i].first);
		if (a[i].second) cnt1--; else cnt0--;
	}
	cout << (res==1e9?-1:res);
	
	
	return 0;
}
