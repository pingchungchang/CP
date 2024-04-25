#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

vector<int> bit;
int n;
void modify(int p,int val){
	for(;p<=n*2;p+= p&-p)bit[p]+= val;
}

int getval(int p){
	int re = 0;
	for(;p>0;p -= p&-p)re += bit[p];
	return re;
}
int main(){
	cin>>n;
	bit = vector<int>(n*2+1,0);
	vector<tuple<int,int,int>> v(n+1,make_tuple(0,0,0));
	vector<int> ans(n+1,0);
	for(int i = 1;i<=2*n;i++){
		int k;
		cin>>k;
		if(get<0>(v[k]) == 0)get<0>(v[k]) = i;
		else get<1>(v[k]) = i;
	}
	for(int i = 1;i<=n;i++)get<2>(v[i]) = i;
	sort(v.begin(),v.end());
	for(int i = n;i>0;i--){
		ans[get<2>(v[i])] = getval(get<1>(v[i]));
		modify(get<1>(v[i]),1);
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
}

