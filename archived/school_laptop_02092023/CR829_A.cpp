#include<bits/stdc++.h>

using namespace std;
int n, inq;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--){
		cin >> n >> s;
		inq = 0; 
		for (int i = 0; i < n; i++){
			if (s[i]=='Q') inq++;
			if (s[i]=='A') inq--;
			inq = max(inq,0);
		}
		cout << (inq?"No\n":"Yes\n");
	}
	
	return 0;
}
