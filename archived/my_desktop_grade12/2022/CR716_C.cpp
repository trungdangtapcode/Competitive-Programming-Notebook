#include<bits/stdc++.h>

using namespace std;
vector<int> v;
int n, p = 1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) if (__gcd(i,n)==1){
		v.push_back(i);
		p = 1ll*p*i%n;
	}
	cout << v.size()-(p!=1) << "\n";
	for (auto it: v) if (it!=p&&p!=1||p==1) cout << it << " ";
	
	return 0;
}
