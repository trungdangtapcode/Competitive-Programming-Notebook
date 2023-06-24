#include <bits/stdc++.h>

using namespace std;
int nhaA, khachB, khachA, nhaB;
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> nhaA >> khachB >> nhaB >> khachA;
	if (nhaA+khachA>nhaB+khachB){
		cout << "A wins";
		return 0;
	}
	if (nhaA+khachA<nhaB+khachB){
		cout << "B wins";
		return 0;
	}
	if (khachA>khachB){
		cout << "A wins";
		return 0;
	}
	if (khachA<khachB){
		cout << "B wins";
		return 0;
	}
	cout << "Extra time";
	return 0;
}
