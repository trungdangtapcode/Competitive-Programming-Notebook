#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
int n, x, y, cnt1, cnt2;
vector<ii> a;
int main(){
	cin >> n >> x >> y;
	a.assign(n,{0,0});
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	sort(a.begin(),a.end());
	int res = 1e9;
	for (int l = 0, r = -1; l < n; l++){
		while ((cnt1<x||cnt2<y)&&r<n-1){
			r++;
			if (a[r].second==1) cnt1++;
			else cnt2++;
		};
		if (cnt1>=x&&cnt2>=y) res = min(res,a[r].first-a[l].first);
		if (a[l].second==1) cnt1--;
		else cnt2--;
	}	
	cout << (res==1e9?-1:res);
	
	
	return 0;
}
