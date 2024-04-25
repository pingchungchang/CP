#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt,avx2,sse4")
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e6+10;
ll N,M;
int cnt[mxn*10];
int lpf[mxn*10];
ll cnt2[mxn*10];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn*10;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn*10;j+=i)lpf[j] = i;
		}
	}
	cin>>N>>M;
	for(int i = 1;i<=N;i++){
		int k;
		cin>>k;
		cnt[k]++;
	}
	for(int i = 1;i<=M;i++){
		int k;
		cin>>k;
		cnt[k]--;
	}
	ll sum = 0;
	for(int i = mxn*10-1;i>=2;i--){
		sum += cnt[i];
		int tmp = i;
		while(tmp != 1){
			cnt2[lpf[tmp]] += sum;
			tmp /= lpf[tmp];
		}
	}
	cout<<(*min_element(cnt2,cnt2+mxn*10)>=0?"Yes":"No");
}
