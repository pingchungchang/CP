#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

const ll mxn = 1e5+10;
ll mods[mxn];
ll pref[mxn];
int main(){
	io
	ll n,m;
	cin>>n>>m;
	mods[0] = 1;
	pref[0] = mods[0];
	for(int i = 1;i<mxn;i++){
		mods[i] = mods[i-1]*10%m;
		pref[i] += pref[i-1]+mods[i];
	}
	for(int i = n-1;i>=0;i--){
		for(int j = 9;j>0;j--){
			if(pref[i]*j%m == 0){
				cout<<string(i+1,'0'+j);
				return 0;
			}
		}
	}
	cout<<-1;
	return 0;
}

