#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 1010;
int n,m,k,l,d;
pii row[mxn],col[mxn];
vector<int> rans,cans;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k>>l>>d;
	for(int i = 1;i<=n;i++)row[i].sc = i;
	for(int i = 1;i<=m;i++)col[i].sc = i;
	for(int i = 0;i<d;i++){
		pii a,b;
		cin>>a.fs>>a.sc>>b.fs>>b.sc;
		if(a.fs == b.fs)col[min(a.sc,b.sc)].fs++;
		else row[min(a.fs,b.fs)].fs++;
	}
	sort(row+1,row+n+1,greater<pii>());
	sort(col+1,col+m+1,greater<pii>());
	for(int i = 1;i<=k;i++)rans.push_back(row[i].sc);
	for(int i = 1;i<=l;i++)cans.push_back(col[i].sc);
	sort(rans.begin(),rans.end());
	sort(cans.begin(),cans.end());
	for(auto &i:rans)cout<<i<<' ';cout<<'\n';
	for(auto &i:cans)cout<<i<<' ';cout<<'\n';
	return 0;
}
