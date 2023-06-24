#include <bits/stdc++.h>

using namespace std;
int n,t;
long long int f[1000005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	for (int i = 1; i <= 1000000; i++) f[i] = i; //f[1] = 0;
	for (int i = 2; i <= 1000000; i++){
		if (f[i]==i) //la snt
			for (int j = i; j <= 1000000; j+=i) f[j] -= f[j]/i;
		//f[i] += f[i-1];
	}
	//for (int i = 1; i <= 10000; i++) f[i] += f[i-1];
	//for (int i = 1; i <= 20; i++) cout << f[i] << " ";
	while (true){
		cin >> n;
		if (n == 0) return 0;
		long long int res = 0;
//		for (int i = 1, j; i <= n; i = j+1){
//			//res += f[i]*(n/i)*(n/i-1)/2;
//			//if (n/i>=0) res += f[n/i]*i*(i-1)/2;
//			j = n / (n/i);
//			res += (n/i)*(n/i-1)/2*(f[j]-f[i-1]);
//		}
		for (int i = 1; i <= n; i++){
			res += f[i]*(n/i)*(n/i-1)/2;
		}
//		vector <int> v;
//		for (int i = 1; i*i <= n; i++) { 
//			v.push_back(i);
//			if (n/i!=i) v.push_back(n/i);
//		}
//		sort(v.begin(),v.end());
//		for (int i = 1; i < v.size(); i++) res += f[n/v[i]]*(v[i]+v[i-1]+1)*(v[i]-v[i-1])/2;
		cout << res << endl;
	}
	return 0;
}
