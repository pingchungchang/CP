#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
pll segtree[mxn*4];
vector<ll> all;
pii req[mxn];
set<ll> lit,fire;
ll sum = 0;

pll add(pll a,pll b){
	return make_pair(a.fs+b.fs,a.sc+b.sc);
}

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].fs += v;
		segtree[now].sc += all[l]*v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].fs = segtree[now*2+1].fs+segtree[now*2+2].fs;
	segtree[now].sc = segtree[now*2+1].sc+segtree[now*2+2].sc;
	return;
}

pll getval(int now,int l,int r,int c){
	if(l == r){
		return make_pair(all[l],all[l]*c);
	}
	int mid = (l+r)>>1;
	if(segtree[now*2+2].fs>=c)return getval(now*2+2,mid+1,r,c);
	pll re = getval(now*2+1,l,mid,c-segtree[now*2+2].fs);
	return make_pair(re.fs,segtree[now*2+2].sc+re.sc);
}

inline ll calc(){
	if(fire.empty()&&lit.empty())return 0;
	if(lit.empty())return sum;
	pll p = getval(0,0,mxn,lit.size());
	if(p.fs<=*lit.begin()){
		return sum+p.sc-*lit.begin()+(fire.empty()?0LL:*fire.rbegin());
	}
	return sum+p.sc;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>req[i].fs>>req[i].sc;
		all.push_back(abs(req[i].sc));
	}
	all.push_back(0);
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	for(int i = 0;i<n;i++){
		if(!req[i].fs){
			if(req[i].sc>0){
				sum += req[i].sc;
				fire.insert(req[i].sc);
				modify(0,0,mxn,lower_bound(all.begin(),all.end(),req[i].sc)-all.begin(),1);
			}
			else{
				sum += req[i].sc;
				fire.erase(-req[i].sc);
				modify(0,0,mxn,lower_bound(all.begin(),all.end(),-req[i].sc)-all.begin(),-1);
			}
		}
		else{
			if(req[i].sc>0){
				sum += req[i].sc;
				lit.insert(req[i].sc);
				modify(0,0,mxn,lower_bound(all.begin(),all.end(),req[i].sc)-all.begin(),1);
			}
			else{
				sum += req[i].sc;
				lit.erase(-req[i].sc);
				modify(0,0,mxn,lower_bound(all.begin(),all.end(),-req[i].sc)-all.begin(),-1);
			}
		}
		cout<<calc()<<'\n';
	}
}
