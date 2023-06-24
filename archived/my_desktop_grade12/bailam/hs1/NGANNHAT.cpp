#include<bits/stdc++.h>

using namespace std;
int n, m, a[1000005], b[1000005], x, y;

bool check(int d){
	for (int i = 1, j = 1+d; j <= 1e6; i++, j++){
		if (a[j]-a[i-1]>=x&&b[j]-b[i-1]>=y) return true;
	}
	return false;
}

int main(){
	freopen("NGANNHAT.INP","r",stdin);
	freopen("NGANNHAT.OUT","w",stdout);
	
	cin >> n >> m;
	cin >> x >> y;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		a[x]++;
	}
	for (int i = 0, x; i < m; i++){
		cin >> x;
		b[x]++;
	}
	for (int i = 1; i <= 1e6; i++) a[i] += a[i-1], b[i] += b[i-1];
	int l = 0, h = 1e6, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){
			h = m-1;
			res = m;
		} else l = m+1;
	}
	cout << res;
	
	return 0;
}
