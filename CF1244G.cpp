#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

typedef tree<ll,null_type,greater<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,tar;
	cin>>n>>tar;
	ll small = n*(n-1)/2;
	ll big = 0;
	for(ll i = 1;i<=n;i++){
		big += max(i,n+1-i);
	}
	ll d = 0;
	for(int i = 1;i<=n/2;i++){
		d += n+1-i-i;
	}
	cout<<small<<' '<<big<<' '<<d<<endl;
	assert(big-small<=d*2);
	return 0;
	if(n*(n-1)/2>tar){
		cout<<"-1";
		return 0;
	}
}
/*
big = n+n-1+n-2+...+n/2+n/2+1+n/2+2+...+n

*/
