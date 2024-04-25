#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define tiii tuple<int,int,int>
#define _all(T) T.begin(),T.end()


const int mxn = 2e5+10;

struct node{
	int sx,sy,ex,ey;
	int val;
};
int n;
node rect[mxn];
vector<int> allx,ally;
pii segtree[mxn*4];
vector<pii> event;

void modify(int now,int l,int r,int s,int e,int v){
	if(l>=s&&e>=r){
		segtree[now].fs+=v;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=s)modify(now*2+1,l,mid,s,e,v);
	if(mid<e)modify(now*2+2,mid+1,r,s,e,v);
	segtree[now].sc = max(segtree[now*2+1].fs+segtree[now*2+1].sc,segtree[now*2+2].fs+segtree[now*2+2].sc);
	return;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>rect[i].sx>>rect[i].sy>>rect[i].ex>>rect[i].ey>>rect[i].val;
		allx.push_back(rect[i].sx);allx.push_back(rect[i].ex);
		ally.push_back(rect[i].sy);ally.push_back(rect[i].ey);
	}
	sort(allx.begin(),allx.end());sort(ally.begin(),ally.end());
	allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	for(int i = 1;i<=n;i++){
		rect[i].sx = lower_bound(_all(allx),rect[i].sx)-allx.begin();
		rect[i].ex = lower_bound(_all(allx),rect[i].ex)-allx.begin();
		rect[i].sy = lower_bound(_all(ally),rect[i].sy)-ally.begin();
		rect[i].ey = lower_bound(_all(ally),rect[i].ey)-ally.begin();
		event.push_back({rect[i].sy,i});
		event.push_back({rect[i].ey+1,-i});
	}
	sort(event.begin(),event.end());
	int pt = 0;
	int sum = 0;
	int ans = 0;
	for(int i = 0;i<ally.size();i++){
		while(pt<event.size()&&event[pt].fs == i){
			if(event[pt].sc>0)sum += rect[event[pt].sc].val;
			else sum -= rect[-event[pt].sc].val;
			pt++;
		}
		ans = max(ans,sum);
		modify(0,0,ally.size(),i,i,sum);
	}
	event.clear();
	for(int i = 1;i<=n;i++){
		event.push_back({rect[i].sx,i});
		event.push_back({rect[i].ex+1,-i});
	}
	/*
	for(int i = 1;i<=n;i++){
		cout<<rect[i].sx<<' '<<rect[i].ex<<' '<<rect[i].sy<<' '<<rect[i].ey<<' '<<rect[i].val<<endl;
	}cout<<endl;

   */
	sort(event.begin(),event.end());
	sum = pt = 0;
	for(int i = 0;i<allx.size();i++){
		while(pt<event.size()&&event[pt].fs == i){
			int pos = abs(event[pt].sc);
			if(event[pt].sc>0){
				sum += rect[pos].val;
				modify(0,0,ally.size(),rect[pos].sy,rect[pos].ey,-rect[pos].val);
			}
			else{
				sum -= rect[pos].val;
				modify(0,0,ally.size(),rect[pos].sy,rect[pos].ey,rect[pos].val);
			}
			pt++;
		}
		ans = max(ans,sum+segtree[0].fs+segtree[0].sc);
	}
	cout<<ans;
}
