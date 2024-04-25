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
struct node{
	ll x,y,z;
	node(){}
	node(ll a,ll b,ll c):x(a),y(b),z(c){}
};

const ll inf = 1e12;
const int mxn = 5005;
bitset<mxn>vis;
ll distance(node &a,node &b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
}
int main(){
	io
	int n;
	cin>>n;
	node arr[n];
	for(int i = 0;i<n;i++)cin>>arr[i].x>>arr[i].y>>arr[i].z;
	ll ans = 0;
	ll d[n];
	for(int i = 0;i<n;i++)d[i] = inf;
	d[0] = 0;
	vis[0] = true;
	int now  = 0;
	for(int asd = 1;asd<n;asd++){
		for(int i = 0;i<n;i++){
			d[i] = min(d[i],distance(arr[now],arr[i]));
		}
		pll small = {inf,0};
		for(int i = 0;i<n;i++){
			if(!vis[i]&&small.fs>d[i]){
				small = {d[i],i};
			}
		}
		vis[small.sc] = true;
		now = small.sc;
		ans += small.fs;
	}
	cout<<ans;
}

