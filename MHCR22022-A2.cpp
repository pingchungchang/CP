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
	ll l,r,bl;
	node(){}
};
ll cc = 0;
const ll mxn = 1e6+10;
unordered_map<int,int> mp[2];
int dif = 0;
int arr[mxn];
node req[mxn];
ll n,q;
inline bool cmp(node a,node b){
    return (a.bl)^(b.bl)?a.l<b.l:(((a.bl)&1)?a.r<b.r:a.r>b.r);
}
inline void add(int a,int p){
	if(mp[a][arr[p]] == mp[a^1][arr[p]])dif++;
	mp[a][arr[p]]++;
	if(mp[a][arr[p]] == mp[a^1][arr[p]])dif--;
	return;
}
inline void del(int a,int p){
	if(mp[a][arr[p]] == mp[a^1][arr[p]])dif++;
	mp[a][arr[p]]++;
	if(mp[a][arr[p]] == mp[a^1][arr[p]])dif--;
	return;
}
void solve(){
	ll ans = 0;
	mp[0].clear();
	mp[1].clear();
	dif = 0;
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	cin>>q;
	for(int i = 0;i<q;i++){
		cin>>req[i].l>>req[i].r;
		req[i].bl = (req[i].bl-1)/sqrt(n)/2+1;
	}
	sort(req,req+q,cmp);
	int l1 = 1,r1 = 1,l2 = 1,r2 = 1;
	add(0,l1);
	add(1,l2);
	for(int i = 0;i<q;i++){
		int mid = (req[i].l+req[i].r)>>1;
		while(r1 < mid){
			r1++;
			add(0,r1);
		}
		while(r1>mid){
			del(0,r1);
			r1--;
		}
		while(l1>req[i].l){
			l1--;
			add(0,l1);
		}
		while(l1<req[i].l){
			del(0,l1);
			l1++;
		}
		while(r2<req[i].r){
			r2++;
			add(1,r2);
		}
		while(r2>req[i].r){
			del(1,r2);
			r2--;
		}
		while(l2>mid+1){
			l2++;
			add(1,l2);
		}
		while(l2<mid+1){
			del(1,l2);
			l2++;
		}
		if(dif == 1){
			ans++;
		}
		else{
			del(0,r1);
			r1--;
			l2--;
			add(1,l2);
			if(dif == 1)ans++;
		}
		cout<<i<<endl;
	}
	cout<<"Case #"<<++cc<<": "<<ans<<'\n';
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

