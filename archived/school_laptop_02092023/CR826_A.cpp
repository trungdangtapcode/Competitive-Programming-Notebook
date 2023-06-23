#include<bits/stdc++.h>

using namespace std;
string a, b;
int n, m;

int getDeg(string s){
	if (s=="M") return 0;
	return (s.back()=='S'?-1:1)*s.length();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> a >> b;
		n = getDeg(a);
		m = getDeg(b);
		if (n==m) cout << "=\n";
		else if (n>m) cout << ">\n";
		else cout << "<\n";
	}
	
	return 0;
}
