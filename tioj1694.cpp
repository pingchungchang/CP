#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 3e4+10;
const int sq = sqrt(mxn);
int bit[mxn];
int tans = 0;
int ans[mxn*10];

struct Q{
	int l,r,id;
	Q(){
		l = r = id = 0;
	}
	bool operator<(const Q &b)const{
		return l/sq == b.l/sq?l/sq&1?r>b.r:r<b.r:l<b.l;
	}
};
vector<Q> req;
int arr[mxn];

void modify(int p,int v){
	for(;p<mxn;p+=p&-p)bit[p] += v;
	return;
}
int getval(int s,int e){
	int re = 0;
	for(;e>0;e-= e&-e)re += bit[e];
	s--;
	for(;s>0;s-= s&-s)re -= bit[s];
	return re;
}

inline void addR(int pt){
	tans += getval(arr[pt],mxn-1);
	modify(arr[pt],1);
	return;
}
inline void addL(int pt){
	tans += getval(1,arr[pt]);
	modify(arr[pt],1);
	return;
}
inline void delL(int pt){
	modify(arr[pt],-1);
	tans -= getval(1,arr[pt]);
}
inline void delR(int pt){
	modify(arr[pt],-1);
	tans -= getval(arr[pt],mxn-1);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i = 0;i<q;i++){
		Q tmp;
		tmp.id = i;
		cin>>tmp.l>>tmp.r;
		req.push_back(tmp);
	}
	sort(req.begin(),req.end());
	int pl = 1,pr = 1;
	modify(arr[1],1);
	for(auto &i:req){
		while(pr<i.r)addR(++pr);
		while(pl>i.l)addL(--pl);
		while(pr>i.r)delR(pr--);
		while(pl<i.l)delL(pl++);
		ans[i.id] = tans;
	}
	for(int i = 0;i<q;i++)cout<<ans[i]<<'\n';
	return 0;
}
