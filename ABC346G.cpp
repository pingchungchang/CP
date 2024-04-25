#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int arr[mxn];
vector<int> pos[mxn];
int N;
multiset<int> st;
ll ans = 0;

struct SEG{
#define ls now*2+1
#define rs now*2+2
#define mid ((l+r)>>1)
	pii seg[mxn*4];
	void modify(int now,int l,int r,int s,int e,int v){
		if(l>=s&&e>=r){
			seg[now].sc += v;
			return;
		}
		if(mid>=s)modify(ls,l,mid,s,e,v);
		if(mid<e)modify(rs,mid+1,r,s,e,v);
		seg[now].fs = 0;
		seg[now].fs += (seg[ls].sc?mid-l+1:seg[ls].fs);
		seg[now].fs += (seg[rs].sc?r-mid:seg[rs].fs);
		return;
	}
#undef ls
#undef rs
#undef mid
};
SEG seg;

void del(int p){
	int l = pos[p].end()[-2]+1,r = pos[p].end()[-1];
	seg.modify(0,0,mxn,l,r,-1);
	return;
}
void add(int p){
	int l = pos[p].end()[-2]+1,r = pos[p].end()[-1];
	seg.modify(0,0,mxn,l,r,1);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++)cin>>arr[i];
	for(int i = 1;i<=N;i++)pos[i].push_back(0);
	ll ans = 0;
	for(int i = 1;i<=N;i++){
		if(pos[arr[i]].size()>1)del(arr[i]);
		pos[arr[i]].push_back(i);
		add(arr[i]);
		ans += seg.seg[0].fs;
	}
	cout<<ans;
}
