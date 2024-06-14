#include<bits/stdc++.h>

using namespace std;
int n;
string s;

int check(int i, int j, int len){
	int res = 0;
	for (int c = 0; c < len; c++,i++,j++){
		res += (s[i]!=s[j]);
	}
	return res;
}

void solve(){
	cin >> n;
	cin >> s;
	int res = n;
	for (int i = 1; i <= n; i++) if (n%i==0){
		int len = n/i;
		bool res1 = 1, res2 = 1;
		for (int i = 0, c = 0; i < n; i += len){
			int tmp = check(0,i,len);
			if (tmp==0) continue;
			if (tmp==1){
				if (c==0) c = 1;
				else {
					res1 = 0;
					break;
				}
			}
			if (tmp>1){
				res1 = 0;
				break;
			}
		}
		for (int i = 0, c = 0; i < n; i += len){
			int tmp = check(n-len,i,len);
			if (tmp==0) continue;
			if (tmp==1){
				if (c==0) c = 1;
				else {
					res2 = 0;
					break;
				}
			}
			if (tmp>1){
				res2 = 0;
				break;
			}
		}
		if (res1||res2){
			res = min(res,len);
		}
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
	solve();
}

