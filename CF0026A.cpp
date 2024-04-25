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
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 2;i<=n;i++){
		int now = i;
		vector<int> fac;
		for(int ii = 0;ii<15;ii++)for(int j = 2;j*j<=i;j++){
			if(now%j == 0){
				fac.push_back(j);
				now/=j;
				break;
			}
		}
		if(now != 1)fac.push_back(now);
		sort(fac.begin(),fac.end());
		fac.erase(unique(fac.begin(),fac.end()),fac.end());
		if(fac.size() == 2&&fac[0] != fac[1])ans++;
	}
	cout<<ans;
}
