#include<bits/stdc++.h>

using namespace std;
int n;
string s;
void solve(){
	cin >> n >> s;
	deque<char> d;
	for (char c: s) d.push_back(c); 
	int cnt = 0;
	int pos = 1, k = n;
	vector<int> res;
	while (d.size()){
		if (res.size()>500) return cout << -1 << "\n", void();
		if (d.back()!=d.front()){
			d.pop_back();
			d.pop_front();
			pos++;
			continue;
		}
		if (d.back()=='1'){
			res.push_back(pos-1);
			d.push_front('1');
			d.pop_back();
			pos++;
			k += 2;
		} else {
			res.push_back(k-pos+1);
			d.push_back('0');
			d.pop_front();
			pos++;
			k += 2;
		}
		cnt++;
	}
	cout << res.size() << "\n";
	for (int x: res) cout << x << " "; cout << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
