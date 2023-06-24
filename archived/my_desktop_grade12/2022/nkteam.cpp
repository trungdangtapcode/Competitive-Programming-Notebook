#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
iii a[100005];
int val[100005], n;
void updt(int x, int v){
	for (; x <= 1e5; x += x&-x) val[x] = min(val[x],v);
}
int gett(int x){
	int res = 1e9;
	for (; x > 0; x -= x&-x) res = min(res,val[x]);
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i =1 ; i <= n; i++) val[i] = 1e9;
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		a[x].first = i;
	}
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		a[x].second.first = i;
	}
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		a[x].second.second = i;
	}
	sort(a+1,a+n+1);
	int res =0;
	for (int i = 1; i <= n; i++){
		if (gett(a[i].second.first)>a[i].second.second) res++;
		updt(a[i].second.first,a[i].second.second);
	}
	cout << res;
	
	return 0;
}
