#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>

const int inf = 1e9+10;
const int mxn = 1e5+10;

vector<pii> pos[mxn];
int ans[mxn];
ll tar[mxn];
int N,M,Q;
tiii act[mxn];

namespace INIT{
	vector<int> v[mxn];
	void GO(){
		cin>>N>>M>>Q;
		for(int i = 1;i<=M;i++){
			int k;
			cin>>k;
			v[k].push_back(i);
		}
		for(int i = 1;i<=N;i++)cin>>tar[i];
		for(int i = 1;i<=Q;i++){
			tlll tmp;
			auto &[a,b,c] = act[i];
			cin>>a>>b>>c;
		}
		for(int i = 1;i<=N;i++){
			for(int j = 0;j+1<v[i].size();j++){
				pos[i].push_back(pii(v[i][j],v[i][j+1]));
			}
			if(!v[i].empty())pos[i].push_back(pii(v[i].back(),mxn));
		}
		return;
	}
}

namespace BIS{
	struct BIT{
		ll bit[mxn];
		vector<int> op;
		BIT(){}
		void modify(int p,ll v,bool re = true){
			if(!p)p=1;
			if(re)op.push_back(p);
			for(;p<mxn;p+=p&-p)bit[p] += v;
			return;
		}
		ll getval(int p){
			ll re = 0;
			for(;p>0;p-= p&-p)re += bit[p];
			return re;
		}
		void clear(){
			for(auto &i:op){
				modify(i,-getval(i)+getval(i-1),0);
			}
			op.clear();
			return;
		}
	};
	BIT bit;
	ll tsum[mxn];

	struct D{
		int x,y,coef,id;
		D(int xx,int yy,int ii,int cc):x(xx),y(yy),id(ii),coef(cc){}
		bool operator<(D b)const{
			return x == b.x?id<b.id:x<b.x;
		}
	};
	vector<D> op;

	void sweep(){
		sort(op.begin(),op.end());
		for(auto &i:op){
			if(!i.id){
				bit.modify(i.y,i.coef);
			}
			else{
				tsum[i.id] += bit.getval(i.y);
			}
		}
		return;
	}

	void calc(int l,int r,vector<int> &v){
		if(v.empty())return;
		if(l == r){
			for(auto &i:v)ans[i] = l;
			return;
		}
		int mid = (l+r)>>1;
		for(auto &i:v)tsum[i] = 0;
		op.clear();
		for(auto &i:v){
			for(auto &j:pos[i]){
				op.push_back(D(j.sc,j.fs,i,i));
			}
		}
		for(int i = l;i<=mid;i++){
			auto [a,b,c] = act[i];
			op.push_back(D(b+1,b+1,0,-c));
			op.push_back(D(b+1,a,0,c));
		}
		sweep();
		vector<int> vl,vr;
		for(auto &i:v){
			if(tsum[i]<tar[i]){
				tar[i] -= tsum[i];
				vr.push_back(i);
			}
			else vl.push_back(i);
		}
		bit.clear();
		calc(mid+1,r,vr);
		calc(l,mid,vl);
		return;
	}
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	INIT::GO();
	vector<int> v;
	for(int i = 1;i<=N;i++)v.push_back(i);
	act[Q+1] = tlll(1,M,inf);
	BIS::calc(1,Q+1,v);
	for(int i = 1;i<=N;i++){
		cout<<(ans[i]>Q?-1:ans[i])<<'\n';
	}
	return 0;
}
