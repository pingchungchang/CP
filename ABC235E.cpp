#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e5+10;
int n,q,m;

struct Q{
	int a,b,w,tp;
	Q(){}
	bool operator<(Q b)const{
		return w<b.w;
	}
};
vector<Q> req;
int ans[mxn];
int dsu[mxn];

int root(int k){
	return k == dsu[k]?k:dsu[k] = root(dsu[k]);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i = 1;i<=m;i++){
		Q tmp;
		cin>>tmp.a>>tmp.b>>tmp.w;
		tmp.tp = 0;
		req.push_back(tmp);
	}
	for(int i = 1;i<=q;i++){
		Q tmp;
		cin>>tmp.a>>tmp.b>>tmp.w;
		tmp.tp = i;
		req.push_back(tmp);
	}
	sort(req.begin(),req.end());
	for(int i = 1;i<=n;i++)dsu[i] = i;
	for(auto &i:req){
		int a = i.a,b = i.b;
		if(root(a) == root(b))continue;
		if(i.tp){
			ans[i.tp] = 1;
		}
		else{
			dsu[root(a)] = root(b);
		}
	}
	for(int i = 1;i<=q;i++){
		cout<<(ans[i]?"Yes\n":"No\n");
	}
	return 0;
}
