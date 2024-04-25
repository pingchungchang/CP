#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 1e5+10;
vector<int> tree[mxn];
int n;
vector<int> v;
ll arr[mxn][3];
int ans[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int j = 0;j<3;j++)for(int i = 1;i<=n;i++){
		cin>>arr[i][j];
	}
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int head;
	for(int i = 1;i<=n;i++){
		if(tree[i].size()>2){
			cout<<-1;
			return 0;
		}
		if(tree[i].size() == 1)head = i;
	}
	v.push_back(head);
	do{
		for(auto nxt:tree[head]){
			if(nxt == v.back()||(v.size()>1&&v[v.size()-2] == nxt))continue;
			head = nxt;
			break;
		}
		v.push_back(head);
	}while(tree[head].size() != 1);
	ll small = 1e18;
	int per[3] = {0,1,2};
	int p2[3];
	do{
		ll sum = 0;
		int pt = 0;
		for(auto &i:v){
			sum += arr[i][per[pt]];
			pt++;
			if(pt==3)pt = 0;
		}
		if(sum<small){
			small = sum;
			for(int i = 0;i<3;i++)p2[i] = per[i];
		}
	}while(next_permutation(per,per+3));
	cout<<small<<'\n';
	int pt = 0;
	for(auto &i:v){
		ans[i] = p2[pt];
		pt++;
		if(pt == 3)pt = 0;
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]+1<<' ';
	return 0;
}
