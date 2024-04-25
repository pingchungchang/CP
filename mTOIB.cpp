#include <bits/stdc++.h>
using namespace std;

int n,l,k;
vector<int> v;
int f(int now,int pos,int hp,int ans){
//	cout<<now<<' '<<pos<<' '<<hp<<' '<<ans<<endl;
	if(now == n)return ans;
	if(pos>v[now])hp--;
	if(hp<0)return 0;
	if(pos<0)return 0;
	ans += pos;
	return max(f(now+1,pos,hp,ans),max(f(now+1,pos-1,hp,ans),f(now+1,pos+1,hp,ans)));
}
void solve(){
	cin>>n>>l>>k;
	if(n>250)return;
	v = vector<int>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	int ans = 0;
	for(int i = 0;i<=250;i++){
		if(f(i,0,k,0) == 0)break;
		ans = max(ans,f(i,0,k,0));
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	for(int i = 0;i<t;i++)solve();
}
