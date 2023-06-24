#include <bits/stdc++.h>

using namespace std;

//Duyet trau luon
int solve(int n, int k, std::vector<int> a){
	int mmax = 0;
	for (int i = 0; i < (1<<n); i++){
		if (__builtin_popcount(i)!=k) continue;
		int sum = 0;
		for (int j = 0; j < n; j++) if ((1<<j)&i) sum |= a[j];
		mmax = max(mmax,sum);
	}
	return mmax;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << solve(n,k,a);
	return 0;
}
