#include<bits/stdc++.h>

using namespace std;

char ask(int a, int b, int c, int d){
	cout << "? "<< a << " " << b << " " << c << " "<< d << endl;
	char ch;
	cin >> ch;
	return ch;
}

void solve(){
	int n;
	cin >> n;
	int pos0 = 0, posn = 0;
	for (int i = 1; i < n; i++){
//		if (ask(pos0,pos0,i,i)=='>') pos0 = i;
		if (ask(posn,posn,i,i)=='<') posn = i;
	}
	int posxn = 0;
	vector<int> vec; 
	for (int i = 0; i < n; i++){
		char ch = ask(posn,posxn,posn,i);
		if (ch=='<'){
			vec.clear();
			vec.push_back(i);
			posxn = i;
		} else if (ch=='=') vec.push_back(i);
	}
	int res = vec[0];
	for (int x: vec) if (ask(res,res,x,x)=='>') res = x;
	cout << "! " << posn << " " << res << endl;
}

int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

