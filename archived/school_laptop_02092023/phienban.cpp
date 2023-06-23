#include<bits/stdc++.h>

using namespace std;
int n, p[20];

int findK(int tmp){
	if (tmp<0) return -1;
	int k = 1;
	while (tmp>=10) tmp/=10, k++;
	return k;
}
void del(int& x){
	int k = findK(x);
	if (findK(x-p[k])==k) x -= p[k];
	else if (findK(x-p[k-1])==k-1) x -= p[k-1];
	else x = -1;
}

int main(){
	p[1] = 1;
	for (int i = 2; i <= 19; i++) p[i] = p[i-1]*10+1;
	cin >> n;
	int res = 0;
	while (n!=-1){
		res++;
		del(n);
//		cout << n << endl;
	}
	cout << res;
	
	return 0;
}
