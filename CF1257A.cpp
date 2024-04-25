#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


void solve(){
	int n,a,x,b;
	cin>>n>>x>>a>>b;
	if(a>b)swap(a,b);
	while(a>1&&x){
		x--;
		a--;
	}
	while(b<n&&x){
		x--;
		b++;
	}
	cout<<b-a<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
