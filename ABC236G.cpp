#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,avx2")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 104;
bitset<mxn> row[mxn],col[mxn];
bitset<mxn> mat[mxn],base[mxn],p[mxn];
pii edges[mxn*mxn];
int ans[mxn];
int N,M,L;

inline void mul(bitset<mxn> a[],bitset<mxn> b[]){
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			row[i][j] = a[i][j];
			col[j][i] = b[i][j];
		}
	}
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			a[i][j] = ((row[i]&col[j]).any()?true:false);
		}
	}
	return;
}

inline void calc(){
	for(int i = 1;i<=N;i++){
		for(int j = 1;j<=N;j++){
			row[i][j] = base[i][j];
			col[j][i] = base[i][j];
			mat[i][j] = false;
		}
		mat[i][i] = true;
		p[i] = base[i];
	}
	int tmp = L;
	while(tmp){
		if(tmp&1){
			mul(mat,p);
		}
		tmp>>=1;
		mul(p,p);
	}
	return;
}

void BIS(int l,int r,vector<int>& req){
	if(l == r){
		base[edges[l].fs][edges[l].sc] = true;
		calc();
		for(auto &i:req){
			if(mat[1][i])ans[i] = l;
			else ans[i] = -1;
		}
		base[edges[l].fs][edges[l].sc] = false;
		return;
	}
	int mid = (l+r)>>1;
	vector<int> vl,vr;
	for(int i = l;i<=mid;i++)base[edges[i].fs][edges[i].sc] = true;
	calc();
	for(auto &i:req){
		if(mat[1][i])vl.push_back(i);
		else vr.push_back(i);
	}
	vector<int>().swap(req);
	if(!vr.empty())BIS(mid+1,r,vr);
	for(int i = l;i<=mid;i++)base[edges[i].fs][edges[i].sc] = false;
	if(!vl.empty())BIS(l,mid,vl);
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>L;
	for(int i = 1;i<=M;i++){
		cin>>edges[i].fs>>edges[i].sc;
	}
	vector<int> req;
	for(int i = 1;i<=N;i++){
		req.push_back(i);
	}
	BIS(1,M,req);
	for(int i = 1;i<=N;i++)cout<<ans[i]<<' ';
	return 0;
}
