#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,b;
	cin>>a>>b;
	while(a&&b){
		if(a>=b*2)a %= b*2;
		else if(b>=a*2)b %= a*2;
		else break;
	}
	cout<<a<<' '<<b;
}
