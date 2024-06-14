#include<bits/stdc++.h>

using namespace std;
string s;
void solve(){
	cin >> s;
	string h = s.substr(0,2), m = s.substr(3,2);
	int ih = stoi(h);
	string cl = "AM";
	if (ih>=12) cl = "PM";
	if (ih==0) ih = 12;
	else if (ih>12){
		ih -= 12;
	}
	h = to_string(ih);
	while (h.length()<2) h = "0" + h;
	cout << h << ":" << m << " " << cl << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

