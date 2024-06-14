#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> x({15,6,3,1});
int f(int tmp){
	if (tmp<0) return 1e9;
	int sum = 0;
	for (int it:x){
		sum += tmp/it;
		tmp %= it;
	}
	return sum;
}
void solve(){
	
	cin >> n;
//	int res = 1e9;
//	do {
//		int sum = 0, tmp = n;
//		for (int it:x){
//			sum += tmp/it;
//			tmp %= it;
//		}
//		res = min(res,sum+tmp);
//	} while (next_permutation(x.begin(),x.end()));
//	cout << brute(n) << "\n";
	cout << min({f(n),f(n-10)+1,f(n-20)+2}) << "\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
