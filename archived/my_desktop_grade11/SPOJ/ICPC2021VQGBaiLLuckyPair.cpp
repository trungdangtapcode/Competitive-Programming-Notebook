#include <bits/stdc++.h>

using namespace std;
int spf[10000007], n, cnt[10000007];

int factorize(int x){
	int res = 1;
	while (x!=1){
		int val = spf[x];
		while (x%val==0) x/=val;
		res *= val;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	for (int i = 1; i <= 1e7; i++) spf[i] = i;
	for (int i = 2; i*i <= 1e7; i++) if (spf[i]==i){
		for (int j = i*i; j <= 1e7; j += i) spf[j] = i;
	}	
	cin >> n;
	long long int res = 0;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		a = factorize(a);
		res += cnt[a];
		cnt[a]++;
	}
	cout << res;
	
	
	return 0;
}
