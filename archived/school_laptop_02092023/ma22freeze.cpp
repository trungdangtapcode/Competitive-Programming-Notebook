#include<bits/stdc++.h>

using namespace std;
typedef long double ld;
vector<ld> v;
ld a, b;
int main(){
	cin >> a >> b;
	v.push_back(a+b);
	v.push_back(a-b);
	v.push_back(a*b);
	v.push_back(a/b);
	sort(v.begin(),v.end());
	cout << fixed << setprecision(9);
	for (int i = 3; i >= 0; i--) cout << v[i] << " ";
	
	return 0;
}
