#include <bits/stdc++.h>

using namespace std;

bool binaryString(string n){
	int l = n.length();
	if (n[0]=='0') return false;
	for (int i = 0; i < l; i++) if (n[i]!='0'&&n[i]!='1') return false;
	return true;
}

string n;
int main(){
	cin >> n;
	cout << binaryString(n);
}
