#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 5e5+10;

struct node{
	ll pl,pr,val;
	node(){
		pl = pr = val = 0;
	}
	node(ll ls,ll rs,ll vv){
		val = vv,pl = ls,pr = rs;
	}
};

ll n;
node arr[mxn];
vector<ll> v;
bitset<mxn> done;
int ppp;
priority_queue<pll,vector<pll>,greater<pll>> pq;

void solve(){
	while(!pq.empty())pq.pop();
	v.clear();
	for(int i = 0;i<=ppp;i++){
		done[i] = false;
		arr[i].pl = arr[i].pr = arr[i].val = 0;
	}
	ppp = 0;
	cin>>n;
	for(int i = 0;i<n;i++){
		ll k;
		cin>>k;
		if(!k)continue;
		if(v.empty()||(v.back()/abs(v.back()) != k/abs(k)))v.push_back(k);
		else v.back()+=k;
	}
	for(int i = 0;i<v.size();i++){
		ppp++;
		arr[ppp].val = abs(v[i]);
		arr[ppp].pl = ppp-1;
		arr[ppp-1].pr = ppp;
		pq.push(make_pair(arr[ppp].val,ppp));
	}
	ll ans = 0;
	while(!pq.empty()){
		auto now = pq.top().sc;
		ll tmp = pq.top().fs;
		ans = max(ans,pq.top().fs);
		pq.pop();
		if(done[now])continue;
		ppp++;
		int C = 0;
		int ls = arr[now].pl,rs = arr[now].pr;
		if(ls)arr[ppp].val += arr[ls].val,C++;
		if(rs)arr[ppp].val += arr[rs].val,C++;
		arr[ppp].pl = arr[ppp].pr = 0;
		arr[ppp].val -= (C-1)*tmp;
		if(ls){
			arr[ppp].pl = arr[ls].pl;
			arr[arr[ls].pl].pr = ppp;
		}
		if(rs){
			arr[ppp].pr = arr[rs].pr;
			arr[arr[rs].pr].pl = ppp;
		}
		done[ls] = done[rs] = done[now] = true;
		if(ls||rs)pq.push(make_pair(arr[ppp].val,ppp));
	}
	cout<<ans<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
