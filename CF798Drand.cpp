#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const ll mxn = 1e5+10;
tlll arr[mxn];
pll sum,tsum;
int n;

void check(){
	tsum = {0ll,0ll};
	for(int i = 0;i<n/2+1;i++){
		tsum.fs += get<0>(arr[i]);
		tsum.sc += get<1>(arr[i]);
	}
	if(tsum.fs*2<=sum.fs||tsum.sc*2<=sum.sc)return;
	cout<<n/2+1<<'\n';
	for(int i = 0;i<n/2+1;i++){
		cout<<get<2>(arr[i])<<' ';
	}
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	srand(time(NULL));
	cin>>n;
	for(int i = 0;i<n;i++)cin>>get<0>(arr[i]),get<2>(arr[i]) = i+1,sum.fs += get<0>(arr[i]);
	for(int i = 0;i<n;i++)cin>>get<1>(arr[i]),sum.sc += get<1>(arr[i]);
	do{
		random_shuffle(arr,arr+n);
		check();
	}while(true);
}
