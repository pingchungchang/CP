#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


struct node{
	int id;
	pll pt;
	pll vec;
	node(){}
	bool operator==(node b)const{
		return (pt.fs == b.pt.fs&&pt.sc == b.pt.sc);
	}
};
bool cmp(node a,node b){
	if(a.pt.fs!= b.pt.fs)return a.pt.fs<b.pt.fs;
	else return a.pt.sc<b.pt.sc;
}
ll cross(pll a,pll b){
	return a.fs*b.sc-a.sc*b.fs;
}
int main(){
	int n;
	while(cin>>n){
		if(n == 0)return 0;
		vector<node> pts(n,node());
		for(int i = 0;i<n;i++){
			cin>>pts[i].pt.fs>>pts[i].pt.sc;
			pts[i].id = i;
		}
		sort(pts.begin(),pts.end(),cmp);
		deque<node> convex;
		stack<node> st;
		for(int i = 0;i<n;i++){
			if(st.empty()){
				node tmp;
				tmp.id = pts[i].id;
				tmp.pt = pts[i].pt;
				tmp.vec = make_pair(0,0);
				st.push(tmp);
				continue;
			}
			while(st.size()>1&&cross(make_pair(pts[i].pt.fs-st.top().pt.fs,pts[i].pt.sc-st.top().pt.sc),st.top().vec)<=0)st.pop();
			node tmp;
			tmp.pt = pts[i].pt;
			tmp.id = pts[i].id;
			tmp.vec = make_pair(st.top().pt.fs-pts[i].pt.fs,st.top().pt.sc-pts[i].pt.sc);
			st.push(tmp);
		}
		while(!st.empty()){
			node tmp;
			tmp.id = st.top().id;
			tmp.pt = st.top().pt;
			convex.push_back(tmp);
			st.pop();
		}
		for(int i = n-1;i>=0;i--){
			if(st.empty()){
				node tmp;
				tmp.pt = pts[i].pt;
				tmp.id = pts[i].id;
				tmp.vec = make_pair(0,0);
				st.push(tmp);
				continue;
			}
			while(st.size()>1&&cross(make_pair(pts[i].pt.fs-st.top().pt.fs,pts[i].pt.sc-st.top().pt.sc),st.top().vec)<=0)st.pop();
			node tmp;
			tmp.pt = pts[i].pt;
			tmp.id = pts[i].id;
			tmp.vec = make_pair(st.top().pt.fs-pts[i].pt.fs,st.top().pt.sc-pts[i].pt.sc);
			st.push(tmp);
		}
		while(!st.empty()){
			node tmp;
			tmp.id = st.top().id;
			tmp.pt = st.top().pt;
			convex.push_back(tmp);
			st.pop();
		}
		node ans;
		ans.pt = make_pair((ll)1e9,(ll)1e9);
		ans.id = 0;
		int k = min(4,(int)convex.size());
		for(int i = 0;i<k;i++)convex.push_back(convex[i]);
		convex.erase(unique(convex.begin(),convex.end()),convex.end());
//		cout<<endl<<convex.size()<<endl;for(auto i:convex)cout<<i.pt.fs<<' '<<i.pt.sc<<endl;
//		return 0;
		
		int p = 0;
		for(int i = 0;i<convex.size()-1;i++){
			while(p != convex.size()&&cross(make_pair(convex[i].pt.fs-convex[i+1].pt.fs,convex[i].pt.sc-convex[i+1].pt.sc),make_pair(convex[p+1].pt.fs-convex[p].pt.fs,convex[p+1].pt.sc-convex[p].pt.sc))>=0){
				p++;
				if(ans.id<(convex[p].pt.fs-convex[i].pt.fs)*(convex[p].pt.fs-convex[i].pt.fs)+(convex[i].pt.sc-convex[p].pt.sc)*(convex[i].pt.sc-convex[p].pt.sc)){
					ans.id = (convex[p].pt.fs-convex[i].pt.fs)*(convex[p].pt.fs-convex[i].pt.fs)+(convex[i].pt.sc-convex[p].pt.sc)*(convex[i].pt.sc-convex[p].pt.sc);
					ans.pt = make_pair(convex[i].id,convex[p].id);
					if(ans.pt.fs>ans.pt.sc)swap(ans.pt.fs,ans.pt.sc);
				}
				else if(ans.id == (convex[p].pt.fs-convex[i].pt.fs)*(convex[p].pt.fs-convex[i].pt.fs)+(convex[i].pt.sc-convex[p].pt.sc)*(convex[i].pt.sc-convex[p].pt.sc)){
					pll now = make_pair(convex[p].id,convex[i].id);
					if(now.fs>now.sc)swap(now.fs,now.sc);
					if(now.fs == now.sc)continue;
					if(ans.pt.fs > now.fs)ans.pt = now;
					else if(ans.pt.fs == now.fs&&ans.pt.sc>now.sc)ans.pt = now;
				}
			}
			p--;
		}
		cout<<ans.pt.fs<<' '<<ans.pt.sc<<'\n';	
	}
}

