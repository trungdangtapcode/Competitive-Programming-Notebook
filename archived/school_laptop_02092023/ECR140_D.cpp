#include<bits/stdc++.h>

using namespace std;
int n;
string s;
main(){
	cin >> n >> s;
	int be_better = 0, cnt_higher = 0, be_worse = 0, cnt_lower = 0;	
	for (char c: s){
		if (c=='1'){
			be_better += (1<<cnt_higher);
			++cnt_higher;
		} else {
			be_worse += (1<<cnt_lower);
			++cnt_lower;
		}
	}
	for (int i = be_better+1; i + be_worse <= (1<<n); i++){
		cout << i << " ";
	}
	
	return 0;
}
