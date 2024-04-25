#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 40;

struct mat{
	ll val[mxn][mxn];
	mat(){
		memset(val,0,sizeof(val));
	}
	ll* operator[](int k){
		return (ll*)val[k];
	}
	mat operator*(mat b)const{
		mat re;
		for(int i = 0;i<mxn;i++)for(int j = 0;j<mxn;j++)for(int k = 0;k<mxn;k++)re[i][j] += val[i][k]*b[k][j];
		return re;
	}
};

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	mat now;
	for(int i = 0;i<n;i++)now[i][i] = 1;
	mat re;
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			char c;
			cin>>c;
			re[i][j] = c-'0';
		}
	}
	int s,t,p;
	cin>>s>>t>>p;
	s--,t--;
	ll ans =0;
	for(int i = 1;i<=p;i++){
		now = now*re;
		ans += now[s][t];
	}
	cout<<ans;
}
