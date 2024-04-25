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

const ll mxn = 1e6+10;
struct node{
	node* pl,*pr;
	ll l,r;
	ll sum;
	ll cnt[4];
	node(ll lll,ll rr){
		l = lll,r = rr,sum = 0;
		pl = pr = 0;
		cnt[3] = cnt[0] = cnt[1] = cnt[2] = 0;
	}
};
void init(node* now){
	if(!now)return;
	now->sum = 0;
	now->cnt[0] = now->cnt[1] = now->cnt[2] = now->cnt[3] = 0;
	init(now->pl);
	init(now->pr);
	return;
}
node* segtree = new node(0,mxn);
ll arr[mxn];
void addcnt(node* now,ll p,ll v){
	if(now->l == now->r){
		fill(now->cnt,now->cnt+4,0);
		now->cnt[v]++;
		now->sum = v;
		return;
	}
	ll mid = (now->l+now->r)/2;
	if(!now->pl){
		now->pl = new node(now->l,mid);
		now->pr = new node(mid+1,now->r);
	}
	if(mid>=p)addcnt(now->pl,p,v);
	else addcnt(now->pr,p,v);
	now->sum  =now->pl->sum+now->pr->sum;
	for(int i = 1;i<=3;i++)now->cnt[i] = now->pl->cnt[i]+now->pr->cnt[i];
	return;
}
ll getval(node* now,ll total){
	if(now->l == now->r)return now->l;
	int mid = (now->l+now->r)/2;
	if(now->pl->sum<total)return getval(now->pr,total-now->pl->sum);
	else return getval(now->pl,total);
}
vector<ll> getcnt(node* now,ll s ,ll e){
	if(now->l>=s&&now->r<=e)return {now->cnt[0],now->cnt[1],now->cnt[2],now->cnt[3]};
	int mid = (now->l+now->r)/2;
	if(mid>=e)return getcnt(now->pl,s,e);
	else if(mid<s)return getcnt(now->pr,s,e);
	else{
		auto a= getcnt(now->pl,s,e),b = getcnt(now->pr,s,e);
		return {0,a[1]+b[1],a[2]+b[2],a[3]+b[3]};
	}
}
int cc = 0;
void solve(){
	ll n,m;
	cin>>n>>m;
	cout<<n<<m<<endl;
	ll total = 0;
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		total += k;
		addcnt(segtree,i,k);
	}
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';cout<<'\n';
	ll ans = 0;
	while(m--){
		ll p,v,z;
		cin>>p>>v>>z;
		total -= arr[p];total+=v;
		arr[p] = v;
		addcnt(segtree,p,v);
		auto cnt1 = getcnt(segtree,0,z);
		auto cnt2 = getcnt(segtree,z+1,n);
		ll d = total-(cnt1[1]+cnt1[2]*2+cnt1[3]*3)*2;
		if(d<0){
			for(int i = 0;i<=3;i++)swap(cnt1[i],cnt2[i]);
			d = -d;
		}
		ll k = min(cnt1[1],cnt2[3]);
		if(k*2>=d){
			ans += d/2;
			cnt1[1] -= d/2;
			cnt2[3] -= d/2;
			d %= 2;
		}
		else{
			ans += k;
			cnt1[1] -= k;
			cnt2[3] -= k;
			d -= k*2;
		}
		}
		if(d != 0){
			d -= min(cnt1[1],cnt2[2])+min(cnt1[2],cnt2[3]);
			total += d;
		}
		if(d <= 0){
			ans += total;
		}
		else ans --;
		cout<<ans<<'\n';
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

