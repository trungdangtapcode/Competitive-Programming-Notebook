#include<bits/stdc++.h>

using namespace std;
int n;
bool perfectSquareCheck(int x){
	return ((int)sqrt(x)*(int)sqrt(x)==x);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n;
		bool res = false;
		for (int i = 0, a; i < n; i++){
			cin >> a;
			if (!perfectSquareCheck(a)) res = true;
		}
		cout << (res?"YES\n":"NO\n");
	}
	
	return 0;
}
