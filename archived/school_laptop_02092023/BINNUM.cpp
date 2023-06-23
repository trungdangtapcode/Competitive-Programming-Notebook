#include<bits/stdc++.h>

using namespace std;
long long int a, b, c, d;
int main(){
	cin >> a >> b >> c >> d;
	if (a<b) swap(a,b);
	if (a==c) return cout << (d?1:a-1),0;
	if (b==c) return cout << (d?1:b-1),0;
	if (b>c) cout << (d?1+b-c:a-(1+b-c));
	else cout << (d?1+a-c:a-1-(1+a-c));
	
	return 0;
}
