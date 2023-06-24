#include <bits/stdc++.h>

using namespace std;
int n, t;
bool check(int x){
	if (x==0||x==1) return false;
	for (int i = 2; i*i <= x; i++){
		if (x%i==0) return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	
	while (t--){
		cin >> n;
		int count = 0;
		for (int i = 1; i <= n; i++){
			if (__gcd(i,n)==1) count++;
		}
		cout << (check(count)?"TRUE":"FALSE") << '\n';
	}
}
