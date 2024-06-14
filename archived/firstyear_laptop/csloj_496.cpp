#include<bits/stdc++.h>

using namespace std;

map<char,int> mp;
void solve(){
	mp['C'] = 12;
	mp['H'] = 1;
	mp['O'] = 16;
	
	string str;
	cin >> str;
	vector<long long> s;
	for (char c: str){
		if (c=='('){
			s.push_back(-1);
		} else if (c==')'){
			long long sum = 0;
			while (s.back()!=-1)
				sum += s.back(), s.pop_back();
			s.pop_back();
			s.push_back(sum);
		} else if (mp.count(c)){
			s.push_back(mp[c]);
		} else {
			long long x = s.back();
			s.pop_back();
			s.push_back(x*(c-'0'));
		}
	}
	long long res = 0;
	for (int x: s) res += x;
	cout << res << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

