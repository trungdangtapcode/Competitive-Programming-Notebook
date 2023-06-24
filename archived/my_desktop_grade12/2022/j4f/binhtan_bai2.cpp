#include<bits/stdc++.h>


using namespace std;

bool check(long long x){
	vector<int> v;
	while (x){
		v.push_back(x%10);
		x /= 10;
	}
	int sum[2] = {0,0};
	for (int i = 0; i < v.size(); i++) sum[i%2] += v[i];
	return sum[0] == sum[1]; 
}

long long n;
int main(){
	cin >> n;
	while (!check(n--));
	cout << ++n;
	
	return 0;
}
