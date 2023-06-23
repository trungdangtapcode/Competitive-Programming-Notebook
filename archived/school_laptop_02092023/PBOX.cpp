#include<bits/stdc++.h>

using namespace std;
string s;
int n;
vector<int> start, itm; //intermediate
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++) if (s[i]=='#'){
		start.push_back(i);
		if (start.size()-1==i) itm.push_back(i);
		else {
			itm.push_back(max(i,(itm.empty()?-1:itm.back())+2));
			if (itm.back()>=n-1){
				cout << -1;
				return 0;
			}
		}
	}
	long long int res =0;
	for (int i = 0; i < start.size(); i++){
		res += itm[i]-start[i]+itm[i]-i;
	}
	cout << res;
	
	return 0;
}
