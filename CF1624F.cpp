#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()

int total = 0;
int now = 0;
int n;
bool ask(int k){
	int re = (total/n+1)*n-total+k;
	re %= n;
	total += re;
	cout<<"+ "<<re<<endl;
	cin>>re;
	if(re == now)return true;
	else{
		now = re;
		return false;
	}
}
int main(){
	io
	cin>>n;
	int l = 1,r = n-1;
	while(l != r){
		int mid = (l+r)/2;
		if(ask(mid))l = mid+1;
		else r = mid;
	}
//	cout<<total<<','<<l<<endl;
	cout<<"! "<<now*n+(total+n-l)%n<<endl;
}

