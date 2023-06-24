#include<bits/stdc++.h>

using namespace std;
int n;

int calc(int x){
	int res = 0;
	for (int i = 1; i*i <= x; i++) if (x%i==0){
		res += i + x/i;
		if (i*i==x) res -= i;
	}
	return res;
}

int main(){
	freopen("bai1.inp","r",stdin);
	freopen("bai1.out","w",stdout);
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; i++) if (calc(i)>=n) res += i;
	cout << res;
	return 0;
}
