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
	ll w,h,id;
	node(){}
};
bool cmp(node &a,node &b){
	return a.w<b.w;
}
bool idcmp(node &a,node &b){
	return a.id<b.id;
}
void solve(){
	ll n;
	cin>>n;
	vector<node> v(n,node());
	for(int i = 0;i<n;i++){
		cin>>v[i].w>>v[i].h;
		if(v[i].h<v[i].w)swap(v[i].h,v[i].w);
		v[i].id = i+1;
	}
	sort(_all(v),cmp);
	node a,b;
	a.w = a.h = a.id = b.w = b.h = b.id = INT_MAX;
	ll ans[n+1];
	for(int i = 0;i<n;i++){
		if(v[i].w == a.w){
			if(b.h<v[i].h){
				ans[v[i].id] = b.id;
			}
			else ans[v[i].id] = -1;
			if(a.h>v[i].h){
				a = v[i];
			}
		}
		else{
			if(a.h<v[i].h){
				ans[v[i].id] = a.id;
			}
			else ans[v[i].id] = -1;
			b = a;
			if(a.h>v[i].h){
				a = v[i];
			}
		}
	}
//	for(auto &i:v)cout<<i.id<<' '<<i.h<<' '<<i.w<<',';
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<'\n';
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

