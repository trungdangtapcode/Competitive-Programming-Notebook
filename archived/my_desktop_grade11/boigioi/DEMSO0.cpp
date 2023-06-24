#include <bits/stdc++.h>

using namespace std;
int n;
int c2 = 0, c5 = 0;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int n0 = i;
		while (n0%2==0) c2 ++, n0/=2;
		while (n0%5==0) c5 ++, n0/=5;
	}
	cout << min(c2,c5);
	
	return 0;
}
