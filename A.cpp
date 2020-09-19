#include <bits/stdc++.h>
#define forIn(i, b) for(i=0;i<b;i++)
using namespace std;

#define ll long long

int main()
{
	int p;

	cin>>p;
	int i;
	string namaAwal, namaDest;
	ll xAwal, xDest;
	ll yAwal, yDest;
	ll rAwal, rDest;
	ll jarak = 0;
	vector <tuple <ll, string, string>> vect;

	forIn(i, p){
		cin>>namaAwal>>xAwal>>yAwal>>rAwal>>namaDest>>xDest>>yDest>>rDest;

		jarak = ((xDest-xAwal)*(xDest-xAwal)) + ((yDest-yAwal)*(yDest-yAwal));
		jarak = sqrt(jarak);
		vect.push_back(make_tuple(jarak, namaAwal, namaDest));
	}

	sort(vect.begin(), vect.end());

	for(int i = vect.size()-1; i>=0; i--){
		cout<<get<1>(vect[i])<<" "<<get<2>(vect[i])<<" "<<get<0>(vect[i])<<endl;
	}
	return 0;
}