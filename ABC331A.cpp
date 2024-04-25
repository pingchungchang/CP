#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int M,D;
	cin>>M>>D;
	int y,m,d;
	cin>>y>>m>>d;
	if(d == D){
		m++,d = 1;
	}
	else d++;
	if(m>M){
		m = 1;
		y++;
	}
	cout<<y<<' '<<m<<' '<<d;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t = 1;
	while(t--)solve();
}
