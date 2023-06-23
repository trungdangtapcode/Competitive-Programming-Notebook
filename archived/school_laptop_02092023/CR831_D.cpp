#include<bits/stdc++.h>

using namespace std;
int n, m, k;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> n >> m >> k;
		bool res = true;
		for (int i = 1, x; i <= k; i++){
			//outextra = k - x
			//extra[1..i] = i - outextra
			//it's greedy but the worse will come for the j-th(x+1..) card so it's ok
			//if in extra has n*m-3 cards we can move anything
			//other words it needs n*m-4 (4 empties) to extra card i-th(x) and move to goal
			cin >> x;
			if (n*m-3<i-(k-x)) res = false;
		}
		cout << (res?"YA\n":"TIDAK\n");
	}
	
	
	return 0;
}
