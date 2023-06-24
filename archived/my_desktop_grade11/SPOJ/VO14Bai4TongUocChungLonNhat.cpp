#include <bits/stdc++.h>

using namespace std;
long long int f[100005][30], a[100005];
int n;
const int p = 1e9 + 7;

long long int getGCD(int i, int j){
	int lg = log2(j-i+1);
	return __gcd(f[i][lg],f[j-(1<<lg)+1][lg]);
}
int jumpPos(int pos1, int pos2){ //root= pos1, cur = pos2 -> pos3 that getGCD(pos1,pos2) = getGCD(pos1,pos3) fareset
	long long int val = getGCD(pos1,pos2);
	int l = pos2, h = n-1, res = l, m;
	while (l<=h){
		m = (l+h)/2;
//		cout << l << " " << h << " => f(" << m << ") = " << getGCD(pos1,m) << endl;
		if (getGCD(pos1,m)==val){
			res = max(res,m);
			l = m + 1;
		} else h = m - 1;
	}
	return res;
}


int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		f[i][0] = a[i];
	}
	for (int i = 1; (1<<i) <= n; i++){
		for (int j = 0; j + (1<<i) - 1 < n; j++){
			f[j][i] = __gcd(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
	
//	for (int i = 0; (1<<i) <= n; i++){
//		cout << i << ": ";
//		for (int j = 0; j < n; j++) cout << f[j][i] << " ";
//		cout << endl;
//	}
//	cout << jumpPos(0,0);
	long long int res = 0;
	for (int i = 0; i < n; i++){
		int j = i;
		while (j<n){
			int last_j = jumpPos(i,j);
			res = (res+getGCD(i,j)*(last_j-j+1))%p;
			j = last_j + 1;
		}
	}
	cout << res;
	
	return 0;
}
