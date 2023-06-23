#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--){
		cin >> s;
		vector<int> v;
		for (int i = 0, j = 0; i < s.length(); i++){
			if (s[i]!=s[j]){
				if (s[j]=='1') v.push_back(i-j);
				j = i;
			}
			if (i==s.length()-1)
				if (s[i]=='1') v.push_back(i-j+1);
		}
		sort(v.begin(),v.end());
		int res1 = 0, res2 = 0;
		for (int i = 0; i < v.size(); i++) if (i&1) res1 += v[i]; else res2 += v[i];
		cout << max(res1,res2) << "\n";		
	}
	
	
	
	return 0;
}

