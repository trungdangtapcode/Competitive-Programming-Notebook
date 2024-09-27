#include<bits/stdc++.h>

using namespace std;
const int maxN = 505;
int n;
string s;
void solve(){
	cin >> n;
	vector<int> vec;
	for (int i =1 ; i<= n; i++){
		cin >> s;
		int pos = s.find('#');
		vec.push_back(pos+1);
	}
	reverse(vec.begin(),vec.end());
	for (int x: vec){
		cout << x << " ";
	}
	cout <<"\n";
}

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	#ifdef JESSIE
	freopen("input.txt","r",stdin);
	#endif
	int t; cin >> t;
	while (t--)
	solve();
}

