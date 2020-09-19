#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std; 

int main(){
    int n;
    cin >> n;

    int p, q, m;
    for(int i=0; i<n; i++){        
        cin >> p >> q >> m;
        while (m > 0){
            if(p > q){
                p /= 2;
                m--;
            }
            else {
                q /= 2;
                m--;
            }
        }
        if(p > q){
            cout << p << " " << q << endl;
        }
        else {
            cout << q << " " << p << endl;
        }
        
    }
	
	return 0;
}