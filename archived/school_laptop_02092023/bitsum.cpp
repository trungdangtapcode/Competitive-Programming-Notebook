#include<bits/stdc++.h>

using namespace std;
int n, q, x, y, p, a[100005];
long long int val[100005];
void updt(int i, int x){
	x = x - a[i];
	a[i] = x;
	for (;i<=n;i+=(i&-i)) val[i] += x;
}
long long int gett(int i){
	long long int res = 0;
	for (;i>0;i-=(i&-i)) res += val[i];
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("BITSUM.INP","r",stdin);
	freopen("BITSUM.OUT","w",stdout);
	
	cin >> n;
	for (int i = 1, x; i <= n; i++){
		cin >> x;
		updt(i,x);
	}
	cin >> q;
	while (q--){
		cin >> p >> x >> y;
		if (p){
			cout << gett(y)-gett(x-1) << "\n";
		} else updt(x,y);
	}
	
	return 0;
}
