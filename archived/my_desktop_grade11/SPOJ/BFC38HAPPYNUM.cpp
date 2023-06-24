#include <bits/stdc++.h>

using namespace std;
int n;
bool check[405];

int f(int x){
	int res = 0;
	while (x>0){
		res += (x%10)*(x%10);
		x /= 10;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		memset(check,false,sizeof(check));
		cin >> n;
		while (true){
			n = f(n);
			if (n==1){
				cout << "YES\n";
				break; 
			} else if (check[n]){
				cout << "NO\n";
				break;
			}
			check[n] = true;
		}
	}
	
	return 0;
}
