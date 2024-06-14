#include<bits/stdc++.h>
//brute find = https://onlinegdb.com/iHxhsNc-M

using namespace std;
int n;
void f(int x){
	if (x>n){
		cout << x-n+1 << " " << n << "\n";
	} else {
		cout << 1 << " " << x << "\n";
	}
}

void solve(){
	cin >> n;
	if (n==2){
		f(1), f(2);
		return;
	}
	if (n==3){
		f(1), f(2), f(4);
		return;
	}
	f(1); f(2); 
	for (int i = 3; i <= n; i++){
		f((i-3)*2+5);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
	solve();
	cout << "\n";
	}
}

