#include <bits/stdc++.h>
using namespace std;

#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ll __int128


inline ll pw(ll a,ll b){
	ll now= 1;
	while(b--){
		now *= a;
	}
	return now;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	long long tar;
	cin>>tar;
	for(ll i = 1;pw(i,i)<=tar;i++){
		if(pw(i,i)==tar){
			cout<<(long long)i<<'\n';
			return 0;
		}
	}
	cout<<-1;
	return 0;
}
