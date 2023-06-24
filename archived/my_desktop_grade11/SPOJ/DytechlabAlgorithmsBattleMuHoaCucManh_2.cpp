#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int p = 1e9+7;
int phiM[35];
map<int,int>  map_phiM[35];

ii bezout(int a, int b){
    int x1 = 0, x2 = 1, y1 = 1, y2 = 0, x = 0, y = 0, r = 0, q = 0;
    if (b == 0){
        return {1,0};
	}
    while(b > 0){
        q = a/b;
        r = a - b * q;
        x = x2 - x1 * q;
        y = y2 - y1 * q;

        a = b; b = r;
        x2 = x1; x1 = x;
        y2 = y1; y1 = y;
    }
    return {x2,y2};
}
int AmuB(int a, int b, int p){
	int res = 1;
	while (b>0){
		if (b%2) res = (1ll*res*a)%p;
		a = (1ll*a*a)%p;
		b /= 2;
	}
	return res;
}
int phi(int n) {
    int res = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res -= res / i;
        }
    }
    if (n != 1) {
        res -= res / n;
    }
    return res;
}
map<int,int> calcMap(int n){
	map<int,int> m;
	for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            m[i]++;
        }
    }
    if (n>1) m[n]++;
    return m;
}
int calcCoprime(int a, int b, map<int,int> mb){ //x|b and (a,x) = 1
	int res = b;
	for (auto it: mb){
		if (a%it.first==0){
			for (int i = 1; i <= it.second; i++){
				res /= it.first;
			}
		}
	}
	return res;
}

int main(){
	phiM[0] = p;
	for (int i = 1; i <= 30; i++) phiM[i] = phi(phiM[i-1]);
	for (int i = 0; i <= 30; i++) map_phiM[i] = calcMap(phiM[i]);
	for (int i = 0; i <= 30; i++) {
		cout << i << ". " << phiM[i] << endl;
		for (auto it: map_phiM[i]) cout << it.first << "^" << it.second << " ";
		cout << endl;
	}
}
