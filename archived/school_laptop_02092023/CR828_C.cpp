#include<bits/stdc++.h>

using namespace std;
int n;
char c;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> c >> s;
		s = s + s;
		int pos = -1, res = 0;
		for (int i = 0; i < 2*n; i++){
			if (s[i]==c&&pos==-1) pos = i;
			if (s[i]=='g'){
				if (pos!=-1) res = max(res,i-pos);
				pos = -1;
			}
		}
		cout << res << "\n";
	}
	
	return 0;
}
