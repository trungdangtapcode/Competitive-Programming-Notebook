#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>

#include <vector>
#include <bits/stdc++.h> 

using namespace std;

bool compare(int a, int b){
	return (a<=b);
};
  
int main() 
{ 
    vector<int> x;
    int n;
	cin >> n;
  	
  	int temp;
	for (int i = 0; i<n; i++){
  		cin >> temp;
  		x.push_back(temp);
	};
  
    sort(x.begin(), x.end(), compare); 
  
    cout << "Sorted \n"; 
    for (int i = 0; i < x.size(); i++) 
        cout << x[i] << " "; 
  
    return 0; 
} 
