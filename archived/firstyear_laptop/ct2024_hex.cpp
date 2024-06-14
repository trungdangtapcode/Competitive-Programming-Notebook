#include<bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5, mod = 256;
int n;
map<char,int> hexmp;
struct Color{
	int r = 0, g = 0, b = 0;
	Color(string s){
		if  (s=="") return;
		r = hexmp[s[1]]*16+hexmp[s[2]];
		g = hexmp[s[3]]*16+hexmp[s[4]];
		b = hexmp[s[5]]*16+hexmp[s[6]];
		assert(r<256&&g<256&&b<256);
	}
	Color operator-(Color x){
		Color res("");
		res.r = (r-x.r+mod)%mod;
		res.g = (g-x.g+mod)%mod;
		res.b = (b-x.b+mod)%mod;
		return res;
	}
	int getInt(){
		return r*256*256+g*256+b;
	}
};
ostream& operator<<(ostream& o, Color x){
	o << "(" << x.r << "," << x.g << "," << x.b << ")";
	return o;
}
string s[maxN], t;
void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	map<int,int> cnt;
	int res = 0;
	for (int i = 1; i <= n; i++){
		cin >> t;
		Color x(t), y(s[i]);
		int z = (x-y).getInt();
		cnt[z]++;
		res = max(res,cnt[z]);
	}
	long double x = (long double)res/n*100;
	cout << fixed << setprecision(2) << x << "%\n" ;
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (char c = '0'; c <= '9'; c++){
		hexmp[c] = c-'0';
	}
	for (char c = 'A'; c <= 'F'; c++){
		hexmp[c] = c-'A'+10;
	}
//	freopen("input.txt","r",stdin);
//	int t; cin >> t;
//	while (t--)
	solve();
}

