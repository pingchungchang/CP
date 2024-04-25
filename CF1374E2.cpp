#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 2e5+10;
pii segtree[mxn*4];
ll n,m,k;
pii arr[mxn];

void modify(int now,int l,int r,int p,int v){
	if(l == r){
		segtree[now].fs += v;
		segtree[now].sc += v*p;
		return;
	}
	int mid = (l+r)>>1;
	if(mid>=p)modify(now*2+1,l,mid,p,v);
	else modify(now*2+2,mid+1,r,p,v);
	segtree[now].fs = segtree[now*2+1].fs+segtree[now*2+2].fs;
	segtree[now].sc = segtree[now*2+1].sc+segtree[now*2+2].sc;
	return;
}

int getval(int now,int l,int r,int cnt){
	if(l == r){
		return l*cnt;
	}
	int mid = (l+r)>>1;
	if(segtree[now*2+1].fs>=cnt)return getval(now*2+1,l,mid,cnt);
	else return segtree[now*2+1].sc+getval(now*2+2,mid+1,r,cnt-segtree[now*2+1].fs);
}

void print(int t){
	priority_queue<pii,vector<pii>,less<pii>> pq[2];
	vector<pii> both;
	set<pii> st;
	for(int i = 0;i<n;i++){
		if(arr[i].sc == 2){
			pq[0].push({arr[i].fs,i});
		}
		else if(arr[i].sc == 1){
			pq[1].push({arr[i].fs,i});
		}
		else{
			if(arr[i].sc == 3)both.push_back({arr[i].fs,i});
			st.insert({arr[i].fs,i});
		}
	}
	sort(both.begin(),both.end());
	while(pq[0].size()>k){
		st.insert(pq[0].top());
		pq[0].pop();
	}
	while(pq[1].size()>k){
		st.insert(pq[1].top());
		pq[1].pop();
	}
	vector<int> ans;
	if(t == -1){
		int d = m-pq[0].size()-pq[1].size();
		while(!pq[0].empty()){
			ans.push_back(pq[0].top().sc);
			pq[0].pop();
		}
		while(!pq[1].empty()){
			ans.push_back(pq[1].top().sc);
			pq[1].pop();
		}
		auto it = st.begin();
		for(int i = 0;i<d;i++){
			ans.push_back(it->sc);
			it++;
		}
		for(auto &i:ans)cout<<i+1<<' ';
		return;
	}
	for(int i = 0;i<both.size();i++){
		st.erase(both[i]);
		while(!pq[0].empty()&&pq[0].size()+i>=k){
			st.insert(pq[0].top());
			pq[0].pop();
		}
		while(!pq[1].empty()&&pq[1].size()+i>=k){
			st.insert(pq[1].top());
			pq[1].pop();
		}
		if(i == t){
			int d = m-pq[0].size()-pq[1].size()-i-1;
			assert(d>=0);
			while(!pq[0].empty()){
				ans.push_back(pq[0].top().sc);
				pq[0].pop();
			}
			while(!pq[1].empty()){
				ans.push_back(pq[1].top().sc);
				pq[1].pop();
			}
			for(int j = 0;j<=i;j++)ans.push_back(both[j].sc);
			auto it = st.begin();
			for(int j = 0;j<d;j++){
				ans.push_back(it->sc);
				it++;
			}
			assert(ans.size() == m);
			for(auto &j:ans)cout<<j+1<<' ';
			return;
		}
	}
	assert(false);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	priority_queue<int,vector<int>,less<int>> pq[2];
	vector<int> both;
	int total = 0;
	for(int i = 0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		arr[i] = {a,(b?2:0)|(c?1:0)};
		if(b==1&&c == 0){
			pq[0].push(a);
			total += a;
		}
		else if(b == 0&&c == 1){
			pq[1].push(a);
			total += a;
		}
		else{
			if(c&b)both.push_back(a);
			modify(0,1,mxn,a,1);
		}
	}
	while(pq[0].size()>k){
		total -= pq[0].top();
		modify(0,1,mxn,pq[0].top(),1);
		pq[0].pop();
	}
	while(pq[1].size()>k){
		total -= pq[1].top();
		modify(0,1,mxn,pq[1].top(),1);
		pq[1].pop();
	}
	sort(both.begin(),both.end());
	pii ans = {INT_MAX,INT_MAX};
	if(min(pq[0].size(),pq[1].size()) == k&&m>=k*2)ans = {total+getval(0,1,mxn,m-k*2),-1};
	for(int i = 0;i<both.size();i++){
		if(i>=m)break;
		total += both[i];
		modify(0,1,mxn,both[i],-1);
		while(!pq[0].empty()&&pq[0].size()+i>=k){
			total -= pq[0].top();
			modify(0,1,mxn,pq[0].top(),1);
			pq[0].pop();
		}
		while(!pq[1].empty()&&pq[1].size()+i>=k){
			total -= pq[1].top();
			modify(0,1,mxn,pq[1].top(),1);
			pq[1].pop();
		}
		if(min(pq[0].size(),pq[1].size())+i+1>=k&&pq[0].size()+pq[1].size()+i+1<=m){
			//cout<<i<<":"<<total+getval(0,1,mxn,m-pq[0].size()-pq[1].size()-i-1)<<endl;
			ans = min(ans,make_pair(total+getval(0,1,mxn,m-pq[0].size()-pq[1].size()-i-1),i));
		}
	}
	if(ans.fs == INT_MAX){
		cout<<-1;
		return 0;
	}
	cout<<ans.fs<<'\n';
	print(ans.sc);
	return 0;
}
/*
6 2 2
21 1 0
60 0 1
16 1 0
75 1 1
31 0 0
16 1 1
*/
