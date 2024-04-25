#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	set<int> x,y;
	for(int i =0;i<4;i++){
		int a,b;
		cin>>a>>b;
		x.insert(a);
		y.insert(b);
	}
	cout<<(*x.rbegin()-*x.begin())*(*y.rbegin()-*y.begin())<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
