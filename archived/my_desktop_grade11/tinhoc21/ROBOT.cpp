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
	int n, x = 0, y = 0;
	string s;
	cin >> n;
	cin >> s;
	char last_status = 'B'; 
	for (int i = 0; i < n; i++){
		char chinput = s[i];
		if (last_status == 'B'){
			if (chinput == 'G'){
				y++;
				last_status = 'B';
			}
			if (chinput == 'L'){
				x--;
				last_status = 'T';
			}
			if (chinput == 'R'){
				x++;
				last_status = 'D';
			}
			if (chinput == 'B'){
				y--;
				last_status = 'N';
			}
		} else if (last_status == 'D'){
			if (chinput == 'G'){
				x++;
				last_status = 'D';
			}
			if (chinput == 'L'){
				y++;
				last_status = 'B';
			}
			if (chinput == 'R'){
				y--;
				last_status = 'N';
			}
			if (chinput == 'B'){
				x--;
				last_status = 'T';
			}
		} else if (last_status == 'N'){
			if (chinput == 'G'){
				y--;
				last_status = 'N';
			}
			if (chinput == 'L'){
				x++;
				last_status = 'D';
			}
			if (chinput == 'R'){
				x--;
				last_status = 'T';
			}
			if (chinput == 'B'){
				y++;
				last_status = 'B';
			}
		} else if (last_status == 'T'){
			if (chinput == 'G'){
				x--;
				last_status = 'T';
			}
			if (chinput == 'L'){
				y--;
				last_status = 'N';
			}
			if (chinput == 'R'){
				y++;
				last_status = 'B';
			}
			if (chinput == 'B'){
				x++;
				last_status = 'D';
			}
		}
		//cout << x << " " << y << endl;
	}
	cout << x << " " << y;
	return 0;
}
