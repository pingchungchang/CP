#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3030;
deque<int> paths[mxn];
int deg[mxn],arr[mxn];
int n,m;
int range[mxn];
queue<int> q;

bool check(){
	bool flag = false;
	fill(deg+1,deg+m+1,0);
	for(int i = 1;i<=m;i++){
		for(auto nxt:paths[i])deg[nxt]++;
	}
	for(int i = 1;i<=m;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(auto nxt:paths[now]){
			deg[nxt]--;
			if(!deg[nxt])q.push(nxt);
		}
	}
	if(*max_element(deg+1,deg+m+1) != 0)return false;
	else return true;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>n>>m>>q;
	for(int i = 1;i<=n;i++)cin>>arr[i];
	range[n] = range[n+1] = range[n+2] = n;
	for(int i = n-2;i>=1;i-= 2){
		int a = arr[i],b = arr[i+1],c = arr[i+2];
		paths[c].push_front(b);
		paths[a].push_front(b);
		range[i] = range[i+2];
		while(!check()){
			a = arr[range[i]-1];
			b = arr[range[i]];
			if((range[i]-i)&1){
				paths[a].pop_back();
			}
			else{
				paths[b].pop_back();
			}
			range[i]--;
		}
	}
	for(auto &i:paths)i.clear();
	range[n-1] = n-(arr[n] == arr[n-1]);
	if(range[n-1] == n)paths[arr[n-1]].push_back(arr[n]);
	/*
	cout<<"HI"<<endl;
	for(int i = 1;i<=n;i++){
		for(auto &j:paths[i])cout<<i<<','<<j<<endl;
	}cout<<endl;

   */
	for(int i = n-3;i>=1;i-=2){
		//cout<<i<<endl;
		int a = arr[i],b = arr[i+1],c = arr[i+2];
		paths[c].push_front(b);
		paths[a].push_front(b);
		range[i] = range[i+2];
		while(!check()){
			a = arr[range[i]-1],b = arr[range[i]];
			if((range[i]-i)&1){
				assert(!paths[a].empty());
				paths[a].pop_back();
			}
			else{
				assert(!paths[b].empty());
				paths[b].pop_back();
			}
			range[i]--;
		}
		/*
		cout<<i<<" "<<range[i]<<":"<<endl;
		for(int i = 1;i<=m;i++){
			for(auto nxt:paths[i])cout<<i<<','<<nxt<<endl;
		}
		cout<<endl;

	   */
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(range[l]>=r)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
