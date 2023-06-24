#include <bits/stdc++.h>

using namespace std;
const int p = 1e9+7;
int a, n;

int AmuB(int a, int b){
	int res = 1;
	while (b>0){
		if (b%2) res = (1ll*res*a)%p;
		a = (1ll*a*a)%p;
		b/= 2;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> a >> n;
	cout << ( 1ll*(AmuB(a,n+1)-1)*AmuB(a-1,p-2)%p + p)%p;
}
