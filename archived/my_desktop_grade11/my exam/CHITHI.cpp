#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;


int main() {
	ifstream fi("chithi.inp");
	ofstream fo("chithi.out");
	
	int n, M, cmd, tmp, x, y;
	int A[1001], sum[1001];
	
	fi >> n >> M;
	A[0] = 0; sum[0] = 0;
	for (int i = 1; i <= n; i++){ //work on i
		fi >> A[i];
		sum[i] = sum[i-1] + A[i];
	}
	
	for (int i = 1; i <= M; i++){
		fi >> cmd;
		if (cmd == 0){ 
			n++; //work on n
			fi >> tmp >> A[n];
			sum[n] = sum[n-1]+A[n];
		} else { //cmd == 1
			fi >> x >> y;
			cout << sum[y] - sum[x-1] << endl;
		}
	}
	
	fi.close();
	fo.close();
	return 0;
}
