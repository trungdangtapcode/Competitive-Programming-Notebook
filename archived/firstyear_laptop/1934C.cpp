#include<bits/stdc++.h>

using namespace std;
int n, m, d1, d2, d3;
void solve(){
	cin >> n >> m;
	cout << "? 1 1" << endl;
	cin >> d1; //x1 + y1 = d1 + 2
	cout << "? "<< n << " " << m << endl;
	cin >> d2; //x2 + y1 = n + m - d2
	cout << "? "<< n << " 1" << endl;
	cin >> d3; //n - x + y - 1 = d2 => y - x = d3-n+1
	int y = (d1+2+d3-n+1)/2, x = (d1+2-d3+n-1)/2;
	x = max(min(x,n),1);
	y = max(min(y,m),1);
	cout << "? " << x << " " << y << endl;
	int tmp; cin >> tmp;
	if (tmp==0){
		cout << "! " << x << " " << y << endl;
		return;
	} 
	y = (n+m-d2+d3-n+1)/2, x = (n+m-d2-d3+n-1)/2;
	cout << "! " << x << " " << y << endl;
	return;
}
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
	
	return 0;
}
