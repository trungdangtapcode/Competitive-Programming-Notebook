#include<bits/stdc++.h>

using namespace std;
long long n;
void solve(){
	cin >> n;
	while (n>=10){
		int x = n%10;
		if (x==9){
			cout << "NO\n";
			return;
		}
		n /= 10;
		n--;
//		cout << n << "\n";
	}
	if (n==0){
		cout << "YES\n";
	} else{
		cout << "NO\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("input.txt","r",stdin);
	int t; cin >> t;
	while (t--)
	solve();
}

