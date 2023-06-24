#include<bits/stdc++.h>

using namespace std;

bool check(int n){
	int sum = 0;
	for (int i = 1; i*i <= n; i++) if (n%i == 0){
		sum += i + n/i;
		if (i*i==n) sum -= i;
	}
	return sum==2*n;
}
int n;

int main(){
	
	cin >> n;
	while (!check(n--));
	cout << ++n;
	
	return 0;	
}
