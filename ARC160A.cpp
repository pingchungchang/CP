#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[n+1] = {};
	int pos[n+1] = {};
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
		pos[arr[i]] = i;
	}
	bool flag = false;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(pos[j]<i)continue;
			//cout<<i<<","<<j<<' '<<m<<endl;
			if(pos[j] == i){
				//cout<<i<<":"<<j<<":"<<(n-i)*(n-i-1)/2+n<<endl;
				if((n-i-1)*(n-i)/2+n < m){
					m -= (n-i-1)*(n-i)/2+n;
					flag = true;
				}
				else{
					break;
				}
			}
			else{
				if(arr[i]<=j&&!flag){
					if(m>n)m -= n;
					else{
						for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';return 0;
					}
					flag = true;
				}
				m--;
				if(m == 0){
					int s = i,e = pos[j];
					reverse(arr+s,arr+e+1);
					for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';
					return 0;
				}
			}
		}
	}
	for(int i = 1;i<=n;i++)cout<<arr[i]<<' ';return 0;
	assert(false);
	return 0;
}
