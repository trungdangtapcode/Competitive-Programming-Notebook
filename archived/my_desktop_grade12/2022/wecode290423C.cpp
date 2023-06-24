#include<bits/stdc++.h>

using namespace std;

int phi[100005], t;

int getpow(int a, int b, int p){
	int res = 1;
	while (b){
		if (b%2) res = 1ll*res*a%p; 
		a = 1ll*a*a%p;
		b /= 2;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 1; i <= 1e5; i++) phi[i] = i;
	for (int i = 2; i <= 1e5; i++) if (phi[i] == i){
		for (int j = i; j <= 1e5; j += i) phi[j] -= phi[j]/i;
	}
	
	cin >> t;
	while (t--){
		int d, b, c;
		cin >> d >> b >> c;
		for (int k = 1; k <= c; k++){
			long long a = k*c + d;
			if (a % b == 0){
				cout << (a/b)%c << "\n";
				break;
			}
		}
	}
	
	return 0;
}
