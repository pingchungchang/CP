#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

int n,k;
const int mxn = 1010;
int cnt = 0;
bitset<mxn> eq[mxn];
vector<int> vv;

inline int ask(bitset<mxn> &bs){
	cout<<"? ";for(int i = 1;i<=n;i++)if(bs[i])cout<<i<<' ';cout<<endl;
	int re;
	cin>>re;
	assert(re != -1);
	return re;
}


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;

	for(int i = 1;i<=k+1;i++){
		for(int j = 1;j<=k+1;j++)eq[i][j] = 1;
		eq[i][i] = 0;
		eq[i][n+1] = ask(eq[i]);
	}
	for(int i = k+2;i<=n;i++){
		for(int j = 1;j<k;j++)eq[i][j] = 1;
		eq[i][i] = 1;
		eq[i][n+1] = ask(eq[i]);
	}

	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			if(eq[j][i]){
				swap(eq[j],eq[i]);
				break;
			}
		}
		for(int j = i+1;j<=n;j++){
			if(eq[j][i]){
				eq[j] ^= eq[i];
			}
		}
	}
	/*
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n+1;j++)cout<<eq[i][j]<<' ';cout<<endl;
	}
   */
	for(int i = n;i>=1;i--){
		for(int j = 1;j<i;j++){
			if(eq[j][i])eq[j] ^= eq[i];
		}
	}
	int ans[n+1];
	for(int i = 1;i<=n;i++){
		ans[i] = eq[i][n+1];
	}
	cout<<"! ";for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';cout<<endl;
}
