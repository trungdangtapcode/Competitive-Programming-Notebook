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

bool *SieveOfEratosthenes(long long int n){
    bool prime[100000];
    memset(prime, true, sizeof(prime));
 
    for (long long int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (long long int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
	return prime;
}

int main() {

	bool *san = SieveOfEratosthenes(100);
	cout << san[1] << endl;
	cout << san[2] << endl;
	cout << san[3] << endl;
	cout << san[4] << endl;
	cout << san[5] << endl;
	cout << san[6] << endl;
	cout << san[7] << endl;
	cout << san[8] << endl;
	cout << san[9] << endl;
	cout << san[10] << endl;
	
	//for (int i = 1; i< 100; i ++){
	//	cout << san[i] << endl;
	//}
	
	
	return 0;
}
