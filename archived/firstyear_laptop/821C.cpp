#include<bits/stdc++.h>

using namespace std;
int n;
//priority_queue<int> st
void solve(){
	cin >> n;
	deque<int> d;
	int res = 0;
	for (int i = 1, cur = 1; i <= 2*n; i++){
		string s;
		cin >> s;
		if (s=="add"){
			int x;
			cin >> x;
			d.push_back(x);
		} else {
			if (d.size()&&d.back()!=cur){
				d.clear();
				res++;
			} else if (d.size()) d.pop_back();
			cur++;
		}
	}
	cout << res << "\n";

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	int t; cin >> t;
//	while (t--)
	solve();
}

