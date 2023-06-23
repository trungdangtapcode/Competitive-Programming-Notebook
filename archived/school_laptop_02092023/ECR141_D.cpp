#include<bits/stdc++.h>

using namespace std;
int n, a[305], res;
const int t = 2*300*300+1, p = 998244353;
int f[t], new_f[t];
int main(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	f[a[2]+t/2] = 1; //cnt[]
	for (int i = 3; i <= n; i++){
		for (int j = 0; j < t; j++) if (f[j]){
			(new_f[a[i] + j] += f[j]) %= p;
			if (j!=t/2) (new_f[a[i] + t - 1 - j] += f[j]) %= p;
		}
		for (int j = 0; j < t; j++) f[j] = new_f[j], new_f[j] = 0; 
	}
	for (int i = 0; i < t; i++) (res += f[i]) %= p;
	cout << res;
	
	
	return 0;
}
