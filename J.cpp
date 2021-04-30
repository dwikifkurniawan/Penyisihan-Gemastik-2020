#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std; 

bool sort2(const tuple<int, int, int>& a, const tuple<int, int, int>& b){ 
    if(get<1>(a) != get<1>(b))
        return (get<1>(a) < get<1>(b));
    
    return (get<2>(a) < get<2>(b));
} 

int main(){
    int m, s, p;
    cin >> m;

    cin >> s;
    int ds[s], js1, ms1[s], js2, ms2[s];
    char temp;
    for(int i=0; i<s; i++){
        cin >> ds[i] >> js1 >> temp >> ms1[i] >> js2 >> temp >> ms2[i];
        js1 *= 60;
        ms1[i] += js1;
        js2 *= 60;
        ms2[i] += js2;
    }

    cin >> p;
    int dp[p], jp1, mp1[p], jp2, mp2[p];
    vector <tuple <int, int, int>> ans;
    bool flag = false;
    for(int i=0; i<p; i++){
        cin >> dp[i] >> jp1 >> temp >> mp1[i] >> jp2 >> temp >> mp2[i];
        jp1 *= 60;
        mp1[i] += jp1;
        jp2 *= 60;
        mp2[i] += jp2;

        // cari    
        for(int j=0; j<s; j++){
            if(dp[i] == ds[j]){
                int a, b, c;
                a = dp[i];
                if(ms1[j] > mp1[i]){
                    b = ms1[j];
                    if(ms2[j] > mp2[i]){
                        c = mp2[i];
                    }
                    else {
                        c = ms2[j];
                    }
                }
                else {
                    b = mp1[i];
                    if(ms2[j] > mp2[i]){
                        c = mp2[i];
                    }
                    else {
                        c = ms2[j];
                    }
                }
                if(c - b >= m && c - b >= 0){
                    ans.push_back(make_tuple(a, b, c));
                    flag = true;
                }
            }
        }
    }
    
    sort(ans.begin(), ans.end(), sort2);

    if(!flag){
        cout << "ikhlaskan saja" << endl;
    }
    else {
        for(int i=0; i<ans.size(); i++){
            cout << get<0>(ans[i]) << " ";
            int a = get<0>(ans[i]);
            int b = get<1>(ans[i]);
            int c = get<2>(ans[i]);

            if(b/60 < 10){
                cout << 0;
            } 
            cout << get<1>(ans[i])/60 << '.';

            if(b%60 < 10){
                cout << 0;
            }
            cout << get<1>(ans[i])%60 << " ";

            if(c/60 < 10){
                cout << 0;
            }
            cout << get<2>(ans[i])/60 << '.';

            if(c%60 < 10){
                cout << 0;
            }            
            cout << get<2>(ans[i])%60 << endl;
        }
    }
    
	
	return 0;
}