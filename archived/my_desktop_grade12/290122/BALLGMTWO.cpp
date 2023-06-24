#include<bits/stdc++.h>

using namespace std;
#define int long long
int fact[1000005], invF[1000005], pow2[1000005];
const int p = 1e9+7;

int nCr(int n, int r){
	if (r<0||n<0) return 0;
	if (r>n) return 0;
	return fact[n]*invF[r]%p*invF[n-r]%p;
}
int EulerCandies(int numCandies, int numBags){ //[0..numCandies]
	numCandies += numBags; //start from 1 (1..numCandies+1)
	return nCr(numCandies-1,numBags-1);
}

int fitness, numPair, waysFit, waysPair, numGreen;

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	fact[0] = fact[1] = invF[0] = invF[1] = pow2[0] = 1;
	for (int i = 2; i <= 1e6; i++) fact[i] = fact[i-1]*i%p;
	for (int i = 2; i <= 1e6; i++) invF[i] = invF[p%i]*(p-p/i)%p;
	for (int i = 2; i <= 1e6; i++) invF[i] = invF[i-1]*invF[i]%p;
	for (int i = 1; i <= 1e6; i++) pow2[i] = pow2[i-1]*2%p;
	
//	cout << EulerCandies(3,3);
	
	int r, g, b, res = 0;
	cin >> r >> g >> b;
	if (g<b) swap(g,b);
	for (int k = g-b; k <= g+b; k+=2){
		fitness = r-1;
		numPair = (g+b-k)/2;
		numGreen = (g-b)+(k-(g-b))/2; //green in single
		if (fitness>=k&&k+numPair>=fitness){
			waysFit = nCr(fitness,k)*nCr(k,numGreen)%p;
			waysPair = pow2[fitness-k]%p*EulerCandies(numPair-(fitness-k),fitness)%p;
			res += waysFit*waysPair%p;
			res %= p;
		}
		fitness = r;
		if (fitness>=k&&k+numPair>=fitness){
			waysFit = nCr(fitness,k)*nCr(k,numGreen)%p;
			waysPair = pow2[fitness-k]%p*EulerCandies(numPair-(fitness-k),fitness)%p;
			res += 2*waysFit*waysPair%p;
			res %= p;
		}
		fitness = r+1;
		if (fitness>=k&&k+numPair>=fitness){
			waysFit = nCr(fitness,k)*nCr(k,numGreen)%p;
			waysPair = pow2[fitness-k]%p*EulerCandies(numPair-(fitness-k),fitness)%p;
			res += waysFit*waysPair%p;
//			cout << waysFit << "*" << waysPair << endl;
			res %= p;
		}
//		cout << fitness << " " << numPair << " " << numGreen << " = " << res << endl;
	}
	cout << res;
	
	
	return 0;
}
