#include <bits/stdc++.h>

using namespace std;
map<int,int> m;
int n;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin >> n;
	for (int i = 0, x; i < n; i++) cin >> x,m[x]++;
	cout << m.size() << '\n';
	for (auto it: m){
		cout << it.first << " " << it.second << '\n';	
	}
	
	return 0;
}
