#include<bits/stdc++.h>

using namespace std;
int n, x, cnt[1000006];

int main(){
	cin >> n >> x;
	for (int i = 0, a; i < n; i++){
		cin >> a;
		if (a<=1e6) cnt[a]++;
	}
	if (x<0){
		cout << 0;
		return 0;
	}
	long long int res = 0;
	for (int i = 0; 2*i < x; i++){
		res += 1ll*cnt[i]*cnt[x-i];
	}
	if (x%2==0) res += 1ll*cnt[x/2]*(cnt[x/2]-1)/2;
	cout << res;
	
	return 0;
}
