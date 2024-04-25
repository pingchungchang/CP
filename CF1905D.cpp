#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define int ll


const int mxn = 1e6+10;

struct node{
	int l;
	mutable int r,val;
	node(){}
	node(int s,int e,int v){
		l = s,r = e,val = v;
	}
	bool operator<(const node& b)const{
		return l==b.l?r<b.r:l<b.l;
	}
};

set<node> st;
int arr[mxn];
ll ans = 0;
int pos[mxn];
int n;
ll sum = 0;

set<node>::iterator split(int pos){
	auto it = st.lower_bound(node(pos,-1,-1));
	if(it != st.end()&&it->l == pos)return it;
	it--;
	int tr = it->r;
	it->r = pos-1;
	return st.insert(node(pos,tr,it->val)).fs;
}

void add(int p,int v){
	auto lit = split(p);
	assert(lit->l == p);
	for(auto it = lit;it != st.end();it++){
		sum -= (it->r-it->l+1)*it->val;
	}
	st.erase(lit,st.end());
	st.insert(node(p,n-1,v));
	sum += (n-p)*v;
	return;
}

void solve(){
	ans = sum = 0;
	st.clear();
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		pos[arr[i]] = i;
	}
	for(int i = 1;i<n;i++)pos[i] = max(pos[i],pos[i-1]);
	for(int i = 0;i<n;i++)st.insert(node(i,i,pos[i])),sum += pos[i];
	ans = n*n-sum;
	for(int i = 0;i<n;i++){
		add(arr[i],n+i);
		ans = max(ans,(n+i+1)*n-sum);
		//cout<<i<<":"<<sum<<'\n';
		ll tsum = 0;
		//for(auto &j:st)tsum += (j.r-j.l+1)*j.val,cout<<j.l<<' '<<j.r<<' '<<j.val<<',';cout<<'\n';
		//cout<<tsum<<":"<<sum<<'\n'<<'\n';
	}
	cout<<ans<<'\n';
	return;
}

main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
