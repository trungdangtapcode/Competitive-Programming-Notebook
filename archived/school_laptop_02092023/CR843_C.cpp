#include<bits/stdc++.h>

using namespace std;
long long n, x;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> x;
		if ((n&x)!=x){
			cout << "-1\n";
			continue;
		}
		long long res = n;
		for (int i = 62; i >= 0; i--){
			bool a = (x&(1ll<<i)), b = (n&(1ll<<i)), pb = (n&(1ll<<(i+1)));
			if (a==0&&b==1){
				if (pb==1||((1ll<<(i+1))-1)&x) res = -1;
				else res = (n|(1ll<<(i+1)))&~((1ll<<(i+1))-1);
				break;
			}
		}
		cout << res << "\n";
	}
	
	
	return 0;
}
