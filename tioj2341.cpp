#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5e5+10;

ll N,M,K,X;
int arr[mxn],brr[mxn];
int cnt[mxn*2];
int num = 0;

void add(int k){
	if(!cnt[k])num++;
	cnt[k]++;
	return;
}
void del(int k){
	cnt[k]--;
	if(!cnt[k])num--;
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N>>M>>K>>X;
	for(int i = 0;i<N;i++)cin>>arr[i];
	for(int i = 0;i<M;i++)cin>>brr[i];
	int ans = 0;
	for(int i = 0;i<M;i++){
		add(brr[i]);
		if(num<=X)ans = max(ans,i+1);
	}
	int pt = M-1;
	for(int i = 0;i<N;i++){
		add(arr[i]);
		while(pt>=0&&num>X){
			del(brr[pt]);
			pt--;
		}
		if(num<=X)ans = max(ans,pt+1+i+1);
	}
	cout<<ans<<'\n';
	return 0;
}
