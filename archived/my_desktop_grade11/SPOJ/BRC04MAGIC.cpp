#include<bits/stdc++.h>

using namespace std;

unordered_map<int,int> cnt;
int n, a[2005];
long long int res;

int main(){
	
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cnt[a[0]+a[1]]++;
	for (int i = 2; i < n; i++){
		for (int j = i+1; j < n; j++) res += cnt[-(a[i]+a[j])];
		for (int j = 0; j < i; j++) cnt[a[i]+a[j]]++;
	}
	cout << res;
	
	return 0;
}
