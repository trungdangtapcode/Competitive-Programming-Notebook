#include<bits/stdc++.h>

using namespace std;
int n, cnt[10];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		int res = 0;
		for (int i = 0; i < n; i++){
			int mmax = 0, diff = 0;
			memset(cnt,0,sizeof(cnt));
			for (int j = i; j < min(n,i+100); j++){
				cnt[s[j]-'0']++;
				mmax = max(mmax,cnt[s[j]-'0']);
				if (cnt[s[j]-'0']==1) diff++;
				if (mmax<=diff) res++;
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}
