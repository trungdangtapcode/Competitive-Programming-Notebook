#include <bits/stdc++.h>
#define fix cout << "fixed "  << endl;

using namespace std;
int delta = 18, maxIndex = 5e3;
double sumLog[20000];
long long int sumMod[20000], fac[20000];
long long int baseK = 1;
string p;
bool isBreak = false;

const double esilon = 1e-10;
bool sosanh(double a, double b){
	return (abs(a-b) <= esilon);
}

long long int invertIt(long long int x, int y, long long int p){
	y = y - 2;
    long long int res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}


int main(){
	for (int i = 1; i < 60; i++) baseK = baseK*2; baseK--;
	
	cin >> p;
	int l = p.length();
	if (l <= delta) delta = l;
	//cout << p.substr(0,delta) << endl; //9718924709
	//long long int x = stoll(p.substr(0,delta));
	double logP = log(stoll(p.substr(0,delta)))/log(10)+(l-delta);
	//cout << logP;
	long long int modP = stoll(p.substr(l-delta,delta))%baseK;
	
	sumLog[0] = 0; //math error
	sumMod[0] = 1;
	for (int i = 1; i <= maxIndex; i++) sumLog[i] = sumLog[i-1] + log(i)/log(10), sumMod[i] = sumMod[i-1]*i%baseK;
	
	fac[0] = 1;
	for (int i = 1; i < 20000) fac[i] *= fac[i-1]%baseK;
	
	//for (int i = 1; i <= maxIndex; i++) for (int j = i; j <= maxIndex; j++) cout << i << " " << j << " => " << sumLog[j]-sumLog[i-1]<< " == " <<logP << " |  "<< sosanh(sumLog[j]-sumLog[i-1],logP)<< endl;
	for (int i = 1; i <= maxIndex; i++) for (int j = i; j <= maxIndex; j++) 
		if (sosanh(sumLog[j]-sumLog[i-1],logP){//&&(fac[i]*invertIt(fac))) {
			cout << i << " " << j << endl;
			return 0;
		}
	//cout << sumLog[6]-sumLog[4];
}
