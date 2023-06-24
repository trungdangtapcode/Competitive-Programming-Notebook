#include <bits/stdc++.h> 
using namespace std; 
  
#define M 32 
  
bitset<1010> dp[505][505][2];
int main() 
{ 
	dp[1][1][0][0] = 1;
    cout << (dp[1][1][0][0]);
    return 0; 
}
