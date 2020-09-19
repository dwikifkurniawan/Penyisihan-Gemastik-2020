#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std; 

int main(){
    ll n, m;
    ll q;
    cin >> n >> m >> q;
    ll matriks[n][m];
    ll x1, y1, x2, y2;

    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            cin >> matriks[i][j];
        }
    }

    ll matriks2[n][m];
    for(ll i=0; i<m; i++){
        matriks2[0][i] = matriks[0][i];
    }
    for(ll i=1; i<n; i++){
        for(ll j=0; j<m; j++){
            matriks2[i][j] = matriks[i][j]+ matriks2[i-1][j];
        }
    }

    for(ll i=0; i<n; i++){
        for(ll j=1; j<m; j++){
            matriks2[i][j] += matriks2[i][j-1];
        }
    }

    for(ll i=0; i<q; i++){ 
        cin >> x1 >> y1 >> x2 >> y2;
        ll ans = matriks2[x2-1][y2-1];
        if(x1-1 > 0){
            ans -= matriks2[x1-2][y2-1];
        }
        if(y1-1 > 0){
            ans -= matriks2[x2-1][y1-2];
        }
        if(x1-1 > 0 && y1-1 > 0){
            ans += matriks2[x1-2][y1-2];
        }
        cout << ans << endl;
    }

	
	return 0;
}