#include <bits/stdc++.h>

using namespace std;
int n;
long long int C, x;
vector<long long int> a;

long long int tinhsum(){long long int sum = 0; for (auto& i: a) sum += i; return sum;}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> C;
	for (int i = 0; i < n; i++) cin >> x,  a.push_back(x);
	//sort(a.begin(),a.end());
	//long long int sum = 0;
	//for (int i = n-1; i >= 0; i--) sum += a[i], if (sum >= m) 
	if (tinhsum()>=C) cout << "YES"; else cout << "NO"; 
	//cout << tinhsum();
	//5 1000000000000000000
	//100000000000000000000000 10000000000000000000 10000000000000000 20000000000000000000 3000000000000000000
	
	return 0;
}
