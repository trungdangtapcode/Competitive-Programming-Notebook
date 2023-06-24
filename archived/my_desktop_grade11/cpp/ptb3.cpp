#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

const int maxN = 255;
struct pt{ //PT = phuong trinh
	float x[maxN]; 
	float a[maxN];
	float e[maxN-1]; //cuc tri = extreme
	int N, lengthX;
	//a[i] is for x^i; 
};


void binarySearch(pt x, float l, float r){	
};

void solvePT(pt &x){
};

void findDerivative(pt x, pt &y){
	for (int i = 0; i < x.N; i++){
		y.a[i] = x.a[i+1]*(i+1); 
	};	
	y.N = x.N-1;
};

void solve(pt InputPT){
	pt solving[InputPT.N];
	solving[InputPT.N] = InputPT;
	for (int i = InputPT.N-1; i>=1; i--){
		//findDerivative(solving[i+1],solving[i]);
		for (int j = 0; j <= solving[i].N; j++){
			solving[i].a[j] = solving[i+1].a[j+1]*(j+1); 
		};	
		solving[i].N = solving[i+1].N-1;			
	};
	
	cout << solving[1].a[1] << "x + " <<solving[1].a[0] << endl;
};

int main() {
	pt InputPT;
	cin >> InputPT.N;
	for (int i = 0; i <= InputPT.N; i++){
		cin >> InputPT.a[i];	
	}
	pt solving[InputPT.N];
	solving[InputPT.N] = InputPT;
	for (int i = InputPT.N-1; i>=1; i--){
		//findDerivative(solving[i+1],solving[i]);
		for (int j = 0; j <= solving[i].N; j++){
			solving[i].a[j] = solving[i+1].a[j+1]*(j+1); 
		};	
		solving[i].N = solving[i+1].N-1;			
	};
	cout << solving[1].a[1] << "x + " <<solving[1].a[0] << endl;
	
	return 0;
}
