#include <bits/stdc++.h>

using namespace std;
int n;
int a[200005], cnt[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
	
	long long int sum = 0;
	for (int i = 0; i < n; i++) sum += cnt[i]*(cnt[i]-1)/2;
	for (int i = 0; i < n; i++){
		cout << sum - (cnt[a[i]]-1) << '\n';
	}
	
	return 0;
}
