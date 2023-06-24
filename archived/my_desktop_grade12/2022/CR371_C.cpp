#include<bits/stdc++.h>

using namespace std;
#define int long long
int n, res;
main(){
	cin >> n;
	priority_queue<int> slope;
	for (int i = 0, x; i < n; i++){
		cin >> x;
		x -= i;
		slope.push(x);
		if (x<slope.top()){
			res += slope.top()-x;
			slope.pop(); slope.push(x);
		}
	}
	cout << res;
	
	return 0;
}
