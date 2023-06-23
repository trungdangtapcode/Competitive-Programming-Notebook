#include<bits/stdc++.h>

using namespace std;
int n, cnt;
string s;
void backtrack(int k, int val){
	if (k>=n){
		cout << s << "\n";
		cnt++;
		return;
	}
	if (n-(k+1)>=val+1){
		s.push_back('(');
		backtrack(k+1,val+1);
		s.pop_back();
	} 
	if (val>0){
		s.push_back(')');
		backtrack(k+1,val-1);
		s.pop_back();
	}
}

int main(){
	cin >> n;
	backtrack(0,0);
	cout << cnt << "\n";
	return 0;
}
