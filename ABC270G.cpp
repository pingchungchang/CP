#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

int mod;

inline int mad(int a,int b){
	a += b;
	return a>=mod?a-mod:a;
}

struct mat{
	int val[2][2];
	mat(){
		memset(val,0,sizeof(val));
		return;
	}
	int* operator[](int b)const{
		return (int*)val[b];
	}
	mat operator*(mat b){
		mat re;
		for(int i = 0;i<2;i++){
			for(int j = 0;j<2;j++){
				for(int k = 0;k<2;k++){
					re[i][j] = mad(re[i][j],1ll*val[i][k]*b[k][j]%mod);
				}
			}
		}
		return re;
	}
	int operator()(int k)const{
		return mad(1ll*val[0][0]*k%mod,val[0][1]);
	};
};

mat pw(mat a,int b){
	mat re;
	re[0][0] = re[1][1] = 1;
	while(b){
		if(b&1){
			re = re*a;
		}
		a = a*a;
		b>>=1;
	}
	return re;
}

void solve(){
	int a,b,s,g;
	cin>>mod>>a>>b>>s>>g;
	if(s == g){
		cout<<"0\n";
		return;
	}
	if(!a){
		if(g != b)cout<<-1<<'\n';
		else if(g == s)cout<<"0\n";
		else cout<<"1\n";
		return;
	}
	int sq = sqrt(mod)+1;
	map<int,int> mp;
	mat M;
	M[0][0] = a,M[0][1] = b,M[1][1] = 1;

	mat tmp = M;
	mp[g] = 0;
	int psyco = 0;
	for(int i = 1;i<sq;i++){
		mp[tmp(g)] = i;
		tmp = tmp*M;
	}
	mat p = pw(M,sq);
	//cout<<sq<<":\n";
	//for(auto &i:mp)cout<<i.fs<<":"<<i.sc<<'\n';
	//cout<<'\n';
	mat I;I[0][0] = I[1][1] = 1;
	mat now = p;
	mat pre = I;
	for(int i = 1;i<=sq*2+1;i++){
		//cout<<i*sq<<":"<<mad(1ll*now[0][0]*s%mod,now[0][1])<<'\n';
		if(mp.find(now(s)) != mp.end()){
			if(i == 1){
				now = I;
				int ans = 0;
				while(now(s) != g)now = now*M,ans++;
				cout<<ans<<'\n';
				return;
			}
			now = pre;
			int step = sq*(i-1);
			while(mp.find(now(s)) == mp.end()){
				step++;
				now = now*M;
			}
			//cout<<step<<":"<<mp[now(s)]<<' ';
			cout<<step-mp[now(s)]<<'\n';
			return;
		}
		pre = now;
		now = now*p;
	}
	cout<<"-1\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();

}
