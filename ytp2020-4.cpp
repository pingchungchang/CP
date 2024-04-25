#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	int n;
	cin>>n;
	int totals = 0;
	int totalis = 0;
	int ans = 0;
	for(int i = 0;i<n;i++){
		int s;
		cin>>s;
		int ic = 0;
		int totalic = 0,totalc = 0;
		for(int j = 0;j<s;j++){
			int c;
			cin>>c;
			totalc+= c;
			bool flag = true;
			for(int k = 0;k<c;k++){
				string in;
				cin>>in;
				if(in == "11")ic++;
				if(flag&&in == "11"){
					flag = false;
					totalic += c;
				}
			}
		}
		totals += totalc;
		if(ic>=2){
			totalic = totalc;
			ans += totalic;
			totalis++;
		}
		else{
			ans += totalic;
		}
	}
	if(totalis>=(n+2)/3)cout<<totals;
	else cout<<ans;
}

