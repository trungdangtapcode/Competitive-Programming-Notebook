#include<bits/stdc++.h>

using namespace std;

unsigned long long n, c, m, minutes, hours;

int main(){
	cin >> n >> c >> m;
	minutes = (1000*m+n*c-1)/n/c;
	hours = minutes/60;
	minutes %= 60;
	cout << hours << " " << minutes;
	
	return 0;
}
