#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
ii operator+(ii a, ii b){
	return {a.first+b.first,a.second+b.second};
}
ii operator-(ii a, ii b){
	return {a.first-b.first,a.second-b.second};
}
ii operator/(ii a, int b){
	return {a.first/b,a.second/b};
}
int abs(ii a){
	return abs(a.first) + abs(a.second);
}
int dist(ii a, ii b){
	return abs(a-b);
}
ostream& operator<<(ostream& o, ii a){
	o << "("<< a.first << "," << a.second << ")";
	return o; 
}
int n;
string s;
map<char,ii> mp;
map<char,char> op;
void solve(){
	cin >> n >> s;
	s = " " + s;
	ii target = {0,0};
	for (int i = 1; i <= n; i++){
		target = target + mp[s[i]];
	}
	if (target.first%2||target.second%2){
		cout << "NO\n";
		return;
	}
	vector<bool> res(n+1, 0);
	if (target==ii{0,0}){
		if (n==2){
			cout << "NO\n";
			return;
		}
		res[1] = 1;
		int pos = s.find(op[s[1]]);
		res[pos] = 1;
	} else {
		ii cur = {0,0};
		ii half = target/2;
		for (int i = 1; i <= n; i++){
			ii nxt = cur + mp[s[i]];
//			cout << cur << " -> " << nxt << "\n";
			if (dist(nxt,half)==dist(cur,half)+1) continue;
			res[i] = 1;
			cur = nxt;
		}
	}
	for (int i = 1; i <= n; i++) cout << (res[i]?'H':'R'); cout << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	mp['S'] = {0,-1};
	mp['N'] = {0,1};
	mp['W'] = {-1,0};
	mp['E'] = {1,0};
	op['S'] = 'N';
	op['N'] = 'S';
	op['E'] = 'W';
	op['W'] = 'E';
	int t; cin >> t;
	while (t--)
	solve();
}

