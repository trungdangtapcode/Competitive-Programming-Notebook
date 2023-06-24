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

long int daonguoc(long int n){
	long int rem = 0, reverse = 0;
	while(n!=0)    
	{    
    	rem=n%10;      
    	reverse=reverse*10+rem;    
    	n/=10;    
  	}	    
	return reverse;
}

int main() {
	//ifstream fi("input.inp");
	//ofstream fo("output.out");
	
	long int a, b;
	cin >> a >> b;
	cout << max(daonguoc(a),daonguoc(b));
	
	//fi.close();
	//fo.close();
	return 0;
}
