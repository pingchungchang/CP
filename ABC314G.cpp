#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const ll mxn = 3e5+10;
ll m,n,h;
ll atk[mxn],tp[mxn];
set<pll> st;
vector<ll> all;
pll segtree[mxn*4+4];
ll ans[mxn];
ll sum = 0;
ll pre[mxn];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].fs += v;
		segtree[now].sc += all[p]*v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].fs = segtree[now*2+1].fs+segtree[now*2+2].fs;
	segtree[now].sc = segtree[now*2+2].sc+segtree[now*2+1].sc;
}
ll getval(int now,int l,int r,int cnt){
	if(!cnt)return 0LL;
	if(l == r){
		return all[l]*cnt;
	}
	int mid = (l+r)>>1;
	if(cnt>=segtree[now*2+2].fs)return segtree[now*2+2].sc+getval(now*2+1,l,mid,cnt-segtree[now*2+2].fs);
	else return getval(now*2+2,mid+1,r,cnt);
}

inline bool dead(int k){
	auto re = getval(0,0,mxn,k);
	if(re+h<=sum)return true;
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>h;
	for(int i = 0;i<n;i++){
		cin>>atk[i]>>tp[i];
		atk[i] += pre[tp[i]];
		pre[tp[i]] = atk[i];
		all.push_back(atk[i]);
	}
	all.push_back(0);
	sort(all.begin(),all.end());all.erase(unique(all.begin(),all.end()),all.end());
	for(int i = 0;i<n;i++){
		atk[i] = lower_bound(all.begin(),all.end(),atk[i])-all.begin();
	}
	fill(ans,ans+n+1,n);
	int pt = 0;
	for(int i = 0;i<n;i++){
		auto it = st.lower_bound({tp[i],-1});
		if(it == st.end()||it->fs != tp[i]){
			st.insert({tp[i],atk[i]});
			modify(0,0,mxn,atk[i],1);
			sum += all[atk[i]];
		}
		else{
			if(it->sc<atk[i]){
				modify(0,0,mxn,atk[i],1);
				modify(0,0,mxn,it->sc,-1);
			}
			sum -= all[it->sc];
			sum += all[atk[i]];
			st.erase(it);
			st.insert({tp[i],atk[i]});
		}
		/*
		if(i == 2){
			cout<<sum<<','<<all[atk[i]]<<','<<getval(0,0,mxn,0)<<endl;
			cout<<dead(0);
			return 0;
		}

	   */
		while(pt<=m&&dead(pt)){
			//cout<<i<<' '<<pt<<":"<<sum<<' '<<getval(0,0,mxn,pt)<<endl;
			ans[pt++] = i;
		}
	}
	for(int i = 0;i<=m;i++)cout<<ans[i]<<' ';
}
