#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	for (int i = 0, res = 0;; i++){
		int p = s.find('U');
		if (s.find('U')==string::npos){
			cout << (res?"YES":"NO")  << "\n";
			return;
		}
//		cout <<s << "\n";
		int len = s.length();
		s[(p+1)%len] = (s[(p+1)%len]=='U'?'D':'U');
		s[(p-1+len)%len] = (s[(p-1+len)%len]=='U'?'D':'U');
		s.erase(p,1);
		res ^= 1;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

