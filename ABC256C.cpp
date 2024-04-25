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
	int r[3],c[3];
	for(int i = 0;i<3;i++){
		cin>>r[i];
	}
	for(int i = 0;i<3;i++)cin>>c[i];
	ll ans = 0;
	int arr[3][3] = {};
	for(int x = 1;x<=30;x++){
		for(int y = 1;y<=30;y++){
			for(int z = 1;z<=30;z++){
				for(int w = 1;w<=30;w++){
					arr[0][0] = x,arr[0][1]=y,arr[1][0] = z,arr[1][1] = w;
					for(int i = 0;i<3;++i){
						arr[i][2] = c[i]-arr[i][0]-arr[i][1];
						arr[2][i] = r[i]-arr[1][i]-arr[0][i];
					}
					bool flag = true;
					for(int i = 0;i<3;i++){
						if(arr[i][2] <= 0||arr[i][2]+arr[i][1]+arr[i][0] != c[i])flag = false;
						if(arr[2][i] <= 0||arr[2][i]+arr[1][i]+arr[0][i] != r[i])flag = false;
					}
					if(flag)ans++;
				}
			}
		}
	}
	cout<<ans;
}

