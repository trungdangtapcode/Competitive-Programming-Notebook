#include<bits/stdc++.h>

using namespace std;
string s;
int n;
void solve(){
	cin >> s;
	n = s.length();
	int sum = 0;
	for (char c: s) sum += c-'a'+1;
	if (n%2==0){
		cout << "Alice "<< sum << "\n";
		return;
	}
	int b = (min(s[0],s.back())-'a'+1), a = sum - b;
	cout << (a>b?"Alice ":"Bob ") << abs(a-b) << '\n';
	
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
	return 0;
}
