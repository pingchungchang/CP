#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

struct D{
	int tp,a,b,c;
	D(int tt = 0,int aa = 0,int bb = 0,int cc):tp(tp),a(aa),b(bb),c(cc){}
};

const int mxn = 1e5+10;

struct BIT{
	int bit[mxn];
	void modify(int p,int v){
		for(;p<mxn;p+=p&-p)bit[p] ^= v;
		return;
	}
	int getval(int s,int e = -1){
		if(e == -1)swap(s,e);
		int re = 0;
		for(;e>0;e-= e&-e)re ^= bit[e];
		s--;
		for(;s>0;s-= s&-s)re ^= bit[s];
		return re;
	}
};

BIT bit;
int N,M,Q;
vector<Q> op;
int arr[mxn],brr[mxn];
pii range[mxn];
vector<D> v;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>Q;
	for(int i = 1;i<=N;i++){
		cin>>arr[i];bit.modify(i,arr[i]);
	}
	for(int i = 1;i<=M;i++){
		cin>>range[i].fs>>range[i].sc;
		brr[i] = bit.getval(range[i].fs,range[i].sc);
	}
	while(Q--){
		int t;
		cin>>t;
		if(t == 1){
			int p,x;
			cin>>p>>x;
			op.push_back(D(0,p,x));
		}
		else if(t == 3){
			int a,b,c;
			cin>>a>>b>>c;
			op.push_back(D(1,a,b,c));
		}
		else if(t == 3){
			int s,e;
			cin>>s>>e;
			int ans = bit.getval(s,e);
		}
		if(op.size()>B)upd();
	}
}
