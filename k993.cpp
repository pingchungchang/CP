#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int N = 1e5+5;

int n;
int cnt,a[N],tmp[N];

ll mod;

inline ll pw(ll a,ll b){
	ll re = 1;
	while(b){
		if(b&1)re = re*a%mod;
		b>>=1;
		a = a*a%mod;
	}
	return re;
}
inline ll inv(ll k){return pw(k,mod-2);}

bool cmp(int x,int y){
	cnt++;
	return x<y;
}

void merge_sort(int l,int r){
	if(l == r)return;
	int mid = (l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int p = l;
	for(int i = l,j = mid+1;i<=mid||j<=r;){
		if(j>r){
			tmp[p] = a[i];
			p++,i++;
			continue;
		}
		if(i>mid){
			tmp[p] = a[j];
			p++,j++;
			continue;
		}
		bool f = cmp(a[i],a[j]);
		if(f == 1){
			tmp[p] = a[i];
			p++,i++;
		}
		else{
			tmp[p] = a[j];
			p++,j++;
		}
	}
	for(int i = l;i<=r;i++)a[i] = tmp[i];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	int brr[n];
	for(int i = 1;i<=n;i++)brr[i] = i;
	do{
		for(int i = 1;i<=n;i++)a[i] = brr[i];
		merge_sort(1,n);
	}while(next_permutation(brr+1,brr+n+1));
	//for(int i = 1;i<=n;i++)cnt= cnt*inv(i)%mod;
	cout<<cnt;
}
