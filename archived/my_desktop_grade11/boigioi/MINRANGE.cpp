#include <bits/stdc++.h>

using namespace std;
long long int a[100005];
int n, k;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	multiset<long long int> s;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < k-1; i++) s.insert(a[i]);
	for (int i = k-1; i < n; i++){
		cout << *s.begin() << '\n';
		s.erase(a[i-k+1]);
		s.insert(a[i]);
	}
	
	
	return 0;
}
