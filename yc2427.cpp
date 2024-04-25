#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 3e5+10;
vector<int> tree[mxn];
vector<int> v[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i<n;i++){
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for(int i = 1;i<=n;i++){
		for(auto &j:tree[i]){
			v[j].push_back(i);
		}
	}
	for(int i = 1;i<=n;i++){
		int sum = 0;
		for(auto &j:v[i])sum += tree[j].size()-1;
		cout<<sum<<'\n';
	}
	return 0;
}
