#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long x[3];
	long long &a = x[0], &b = x[1], &c = x[2];
	cin >> x[0] >> x[1] >> x[2];
	sort(x,x+3);
	if (a==b&&b==c){
		cout << "YES\n";
		return;
	}
	if ((a+b+c)%4==0&&c==2*a&&a==b){
		cout << "YES\n";
		return;
	}
	if ((a+b+c)%5==0&&(c==3*a&&b==a||c==2*a&&b==2*a)){
		cout << "YES\n";
		return;
	}
	if ((a+b+c)%6==0&&(c==4*a&&b==a||c==3*a&&b==2*a)){
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

