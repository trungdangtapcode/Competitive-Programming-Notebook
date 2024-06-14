#include<bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int,int> ii;
int n, k;
main(){
	cin >> n >> k;
	priority_queue<ii> qp, qn;
	for (int i = 1; i <= n; i++){
		int x, a; cin >> x >> a;
		if (x>0) qp.push({x,a});
		if (x<0) qn.push({-x,a});
	}
	int carry = k, pos = 0, res = 0;
	while (qp.size()){
		int x = qp.top().first, a = qp.top().second; qp.pop();
		res += abs(pos-x);
//		cout << x << " " << a << " " << carry << " " << pos<< "\n";
		int tmp = min(a,carry);
		a -= tmp;
		carry -= tmp;
		if (a){
			res += 2*((a+k-1)/k)*x;
			carry = (a+k-1)/k*k - a;
		}
		pos = x;
	}
	res += abs(pos);
	
	pos = 0; carry = k;
	while (qn.size()){
		int x = qn.top().first, a = qn.top().second; qn.pop();
		res += abs(pos-x);
		int tmp = min(a,carry);
		a -= tmp;
		carry -= tmp;
		if (a){
			res += 2*((a+k-1)/k)*x;
			carry = (a+k-1)/k*k - a;
		}
		pos = x;
	}
	res += abs(pos);
	cout << res;
	
	return 0;
}
