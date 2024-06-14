#include<bits/stdc++.h>
//define x = x * d^cnt
//idea is checking x can decompose or d can decompose 
//but check the exception before each. using cnt

using namespace std;
int x, d;
bool check(int x){
	for (int i = 2; i*i <= x; i++) if (x%i==0) return 0;
	return 1;
}
void solve(){
	cin >> x >> d;
	int cnt = 0;
	while (x%d==0) cnt++, x/= d;
	if (cnt==1){
		cout << "NO\n";
		return;
	}
	if (!check(x)){
		cout << "YES\n";
		return;
	}
	//cnt >= 2
	int sd = sqrt(d);
	if (sd*sd==d&&check(sd)&&cnt==3&&x==sd){
		cout << "NO\n";
		return;
	}
	if (cnt>2&&!check(d)){
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

