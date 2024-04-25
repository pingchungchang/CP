#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	if(n<k*2){
		cout<<-1;
		return 0;
	}
	int ans[n+1] = {};
	int g = n/(k*2)-1;
	for(int i = 0;i<g;i++){
		int l = i*k*2+1,r = l+k*2;
		for(int j = 0;j<k;j++){
			ans[l+j] = l+k+j;
			ans[l+k+j] = l+j;
		}
	}
	int tl = g*k*2+1,tr = n;
	//cout<<tl<<','<<tr<<endl;
	int pt = tl+k;
	assert(pt<=n);
	for(int i = tl;i<=tr;i++){
		ans[i] = pt++;
		if(pt>n)pt = tl;
	}
	for(int i = 1;i<=n;i++)cout<<ans[i]<<' ';
}
