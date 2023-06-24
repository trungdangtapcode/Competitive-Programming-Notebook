#include<bits/stdc++.h>

using namespace std;
int n, mo[1000005];
int main(){
	for (int i = 1; i <= 1e6; i++){
		mo[i] += i;
		for (int j = 2*i; j <= 1e6; j+=i) mo[j] -= mo[i];
	}
//===========================
//	for (int i = 1; i <= n; i++){
//		int j = n/(n/i);
//		res += (j-i+1)*(pref_mo[i])*(n/i)*(n/i);
//		i = j;
//	}
//===========================
	while (true){
		cin >> n;
		if (n==0) break;
		long long int res = 0;
		for (int i = 1; i <= n; i++){
			res += 1ll*mo[i]*(n/i)*((n/i)-1)/2;
		}
		cout << res << "\n";
	}
	return 0;
}
