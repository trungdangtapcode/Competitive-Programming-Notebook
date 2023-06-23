#include<bits/stdc++.h>

using namespace std;
int a[100005], cnt[1100005], n;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		for (int i = 1; i <= n; i++) a[i] = s[i-1]-'0', a[i] += a[i-1];
		fill(cnt,cnt+10*n+n,0);
		cnt[0+n] = 1;
		long long res = 0;
		for (int i = 1; i <= n; i++){
			res += cnt[a[i]-i+n];
			cnt[a[i]-i+n]++;
		}
		cout << res << "\n";
	}
	
	return 0;
}
