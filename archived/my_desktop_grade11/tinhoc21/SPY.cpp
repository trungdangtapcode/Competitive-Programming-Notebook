#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
//#include <algorithm>
//functional
//limit
//numeric_limits

using namespace std;


int main() {
	long int x, y, k;
	string s;
	bool ch = false;
	cin >> x >> y >> k;
	long int tx = 0, ty = 0;
	cin >> s;
	for (long int i = 0; i < k; i++){
		if (((tx==x-1)||(tx==x)||(tx==x+1))&&((ty==y-1)||(ty==y)||(ty==y+1))){
			cout << i << endl;
			ch = true;
		}
		char chinput = s[i];
		if (chinput=='U') ty++;
		if (chinput=='R') tx++;
		if (chinput=='D') ty--;
		if (chinput=='L') tx--;
	}
	if (((tx==x-1)||(tx==x)||(tx==x+1))&&((ty==y-1)||(ty==y)||(ty==y+1))) {cout << k; ch = true;} //du am
	if (ch == false) cout << -1;
	return 0;
}
