#include<bits/stdc++.h>

using namespace std;
int w, d, h, a, b, f, g;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> w >> d >> h >> a >> b >> f >> g;
		cout << h+min({
			abs(a-f)+b+g, abs(a-f)+2*d-b-g,
			abs(b-g)+a+f, abs(b-g)+2*w-a-f
		}) << "\n";
	}
	return 0;
}
