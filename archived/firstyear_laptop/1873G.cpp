#include<bits/stdc++.h>

using namespace std;
/*
int n, f[200005][3], a[200005];
void solve(){
	string s;
	cin >> s;
	for (int i = 1; i <= s.length(); i++){
		char c = s[i-1];
		a[i] = c-'A';
		if (i>1||true) f[i][0] = f[i][1] = f[i][2] = -1e9;
	}
	for (int i = 1; i < s.length(); i++){
		if (a[i]){
//			f[i][2] = max(f[i][2],f[i-1][0]+1);
//			f[i][2] = max({f[i][2],f[i-1][0],f[i-1][1],f[i-1][2]});
//			f[i][1] = max({f[i][1],f[i-1][0],f[i-1][1],f[i-1][2]});
			f[i][0] = max(f[i][0],max(f[i-1][2]+1,f[i-1][1]));
			f[i][1] = max(f[i][1],f[i-1][1]);
			f[i][2] = max(f[i][2],f[i-1][1]);
		} else {
			f[i][2] = max(f[i][2],f[i-1][0]);
			f[i][1] = max(f[i][1],max(f[i-1][1]+1,f[i-1][0]));
			f[i][0] = max(f[i][0],f[i-1][0]);
//			f[i][1] = max({f[i][1],f[i-1][0],f[i-1][1],f[i-1]	[2]});
//			f[i][0] = max({f[i][0],f[i-1][0],f[i-1][1],f[i-1][2]});
		}
		cout << f[i][0] << " " << f[i][1] << " " << f[i][2] << "\n";
	}
//	int res = -1;
//	for (int i = 0; i < 3; i++) res = max(res,f[s.length()][i]);
	cout << f[s.length()-1][a[s.length()]] << "\n";
}
*/

void solve(){
	string s;
	cin >> s;
	s.push_back('B');
	int mmin = s.length(), sum =0;
//	if (s[0]=='B'||s[s.length()-2]=='B') mmin = 0;
	for (int i = 1, cnt = 0; i <= s.length(); i++){
		if (s[i-1]=='B'){
				sum += cnt;
				mmin = min(mmin,cnt);
				cnt = 0;
		} else cnt++;
	}
	cout << sum-mmin << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}

