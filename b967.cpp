#include <bits/stdc++.h>
using namespace std;

struct node{
	vector<int> child;
	vector<int> heights;
	int height;
	node(){
		height = -1;
	}
};
int n;
vector<node> v;
int ans = 0;
int rec(int now,int h){
//	cout<<now<<' '<<h<<'\n';
	v[now].height = h;
	if(v[now].child.size()==0)return h;
	for(int i = 0;i<v[now].child.size();i++){
		int nxt = v[now].child[i];
		v[now].heights.push_back(rec(nxt,h+1));
	}
	if(v[now].heights.size()==1){
		ans = max(ans,v[now].heights[0]-v[now].height);
		return v[now].heights[0];
	}
	sort(v[now].heights.begin(),v[now].heights.end());
	int s = v[now].heights.size();
	ans = max(ans,v[now].heights[s-1]-v[now].height+v[now].heights[s-2]-v[now].height);
	return v[now].heights[s-1];
}
void solve(){
	ans = 0;
	v = vector<node>(n,node());
	long long sum = 1LL*n*(n-1)/2;
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		sum -= b;
		v[a].child.push_back(b);
	}
	int root = (int)sum;
	rec(root,0);
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>n){
		if(n == -1)return 0;
		solve();
	}
}
