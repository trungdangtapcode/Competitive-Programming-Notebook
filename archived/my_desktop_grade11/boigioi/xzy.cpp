#include <bits/stdc++.h>

using namespace std;
int n;
long long int k, a[15005];

bool check(long long int x){
	int res = 1;
	long long int dl = 0; //dung luong
	for (int i = 0; i < n; i++){
		if (a[i]>x) return false;
		if (dl+a[i]>x){
			res++;
			dl = a[i];
		} else dl += a[i];
	}
	return (res<=k);
}

int main(){
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	long long int l = 0, h = 1e9, m, res = -1;
	while (l<=h){
		m = (l+h)/2;
		if (check(m)){ //ok, giam m
			res = m;
			h = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << res;
	
	
	return 0;
}
