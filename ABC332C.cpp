#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll n,m;
string s;
pll big,now;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(auto &i:s){
		if(i == '1')now.fs++;
		else if(i == '2')now.sc++;
		else{
			now.fs = now.sc = 0;
		}
		big.fs = max(big.fs,now.fs);
		big.sc = max(big.sc,now.sc);
	}
	cout<<max(0ll,m-big.fs)+big.sc;
}
