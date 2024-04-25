#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


ll a,b;
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	pll now = make_pair(0,0);
	while(n--){
		if(now.fs == a)now.fs = 0;
		else if(!now.sc)now.sc = b;
		else{
			ll d = min(now.sc,a-now.fs);
			now.fs += d;
			now.sc -= d;
		}
	}
	cout<<now.fs<<' '<<now.sc;
}
