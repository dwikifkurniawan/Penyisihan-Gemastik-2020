#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std; 

int main(){
    int n;
	cin >> n;
	int s[n];
	for(int i=0; i<n; i++){
		cin >> s[i];
	}

    int dp[n][n];
	// basecase
	for(int l=0; l < n; l++){
		dp[l][l] = 1;
	}

	for(int j=1; j<n; j++){		
		for(int l=0; l<n-j; l++){
			int r = l+j;
			if(s[l] == s[r] && j == 1){
				dp[l][r] = 2;
			}
			else if(s[l] == s[r]){
				dp[l][r] = dp[l+1][r-1] + 2;
			}
			else {
				dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
			}
		}
	}

	cout << n - dp[0][n-1] << endl;
	
	return 0;
}