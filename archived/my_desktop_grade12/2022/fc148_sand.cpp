#include<bits/stdc++.h>

using namespace std;
long long s, a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> a >> s;
		cout << ((s-2*a&a)==0&&s>=2*a?"Yes\n":"No\n");
	}
	
	return 0;
}

// long code (locac): https://oj.vnoi.info/src/2854752
