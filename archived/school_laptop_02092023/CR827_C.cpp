#include<bits/stdc++.h>

using namespace std;
string s[8];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	int t; cin >> t;
	while (t--){
		for (int i = 0; i < 8; i++) cin >> s[i];
		bool ok = false;
		for (int i = 0; i < 8; i++){
			if (s[i]=="RRRRRRRR") ok = true;
		} 
		cout << (ok?"R\n":"B\n");
	}
	
	
	return 0;
}
