#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second

const ll mxn = 2e5+10;
const ll inf = 1e18;
pll segtree[mxn*4];
ll arr[mxn];
int lp[mxn],rp[mxn];

void modify(int now,int l,int r,int p,ll v){
	if(l == r){
		segtree[now].fs = segtree[now].sc = v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].fs = min(segtree[now*2+1].fs,segtree[now*2+2].fs);
	segtree[now].sc = max(segtree[now*2+1].sc,segtree[now*2+2].sc);
	return;
}

pll getval(int now,int l,int r,int s,int e){
	if(l>=s&&e>=r)return segtree[now];
	int mid = (l+r)>>1;
	pll re = {inf,-inf};
	if(mid>=s){
		auto tmp = getval(now*2+1,l,mid,s,e);
		re.fs = min(re.fs,tmp.fs);
		re.sc = max(re.sc,tmp.sc);
	}
	if(mid<e){
		auto tmp = getval(now*2+2,mid+1,r,s,e);
		re.fs = min(re.fs,tmp.fs);
		re.sc = max(re.sc,tmp.sc);
	}
	return re;
}


void solve(){
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		lp[i] = 1,rp[i] = n;
	}
	vector<int> st;
	for(int i = 1;i<=n;i++){
		while(!st.empty()&&arr[st.back()]<arr[i]){
			rp[st.back()] = i-1;
			st.pop_back();
		}
		st.push_back(i);
	}
	st.clear();
	for(int i = n;i>=1;i--){
		while(!st.empty()&&arr[st.back()]<arr[i]){
			lp[st.back()] = i+1;
			st.pop_back();
		}
		st.push_back(i);
	}
	for(int i = 1;i<=n;i++){
		arr[i] += arr[i-1];
	}
	for(int i = 0;i<=n;i++)modify(0,0,n,i,arr[i]);
	for(int i = 1;i<=n;i++){
		auto tl = getval(0,0,n,lp[i]-1,i-1);
		auto tr = getval(0,0,n,i,rp[i]);
		//cout<<i<<":"<<lp[i]<<','<<tl.fs<<','<<tl.sc<<endl;
		if(tr.sc-tl.fs>arr[i]-arr[i-1]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
