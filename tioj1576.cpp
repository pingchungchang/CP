#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int a,b,c,d;
bool fulfill(int x,int y,int z){
	if(y+x<=a&&y+z<=b&&x<=c&&z<=d)return true;
	else return false;
}
int main(){
	cin>>a>>b>>c>>d;
	pair<int,tuple<int,int,int>> ans;
	int x= 0,y=0,z=0;
	for(;x<=5000;x++){
		for(y = 0;y<=5000;y++){
			z = min(b-y,d);
			if(fulfill(x,y,z)){
				ans = max(ans,make_pair(80*x+100*y+60*z,make_tuple(x,y,z)));
			}
		}
	}
	printf("%d %d %d\n%d",get<0>(ans.sc),get<1>(ans.sc),get<2>(ans.sc),ans.fs);
}

