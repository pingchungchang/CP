#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const ll mxn = 3e5+10;
__int128 ans = 9e18;
__int128 area = 0;
pll conv[mxn];
__int128 sum;
int n;

bool smaller(int s,int e){
	auto tsum = sum;
	tsum += conv[e].fs*conv[s].sc-conv[e].sc*conv[s].fs;
	tsum = abs(tsum*4);
	//cout<<s<<":"<<e<<":"<<(ll)tsum*4<<","<<(ll)abs(area-abs(tsum*4))<<endl;
	//assert(abs(area-abs(tsum*4))<=5e18);
	ans = min(ans,abs(area-tsum));
	return tsum<area;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)cin>>conv[i].fs>>conv[i].sc;
	for(int i = n+1;i<=n*2;i++)conv[i+n] = conv[i] = conv[i-n];
	for(int i = 2;i<=n;i++)area += conv[i-1].fs*conv[i].sc-conv[i-1].sc*conv[i].fs;
	area += conv[n].fs*conv[1].sc-conv[n].sc*conv[1].fs;
	area = abs(area);
	ans = area;
	//cout<<(ll)area<<endl;
	int pt = 1;
	for(int i = 1;i<=n;i++){
		if(pt<=i){
			pt = i;
			sum = 0;
		}
		while(pt<n+i&&smaller(i,pt)){
			pt++;
			sum += conv[pt-1].fs*conv[pt].sc-conv[pt-1].sc*conv[pt].fs;
		}
		smaller(i,pt);
		sum -= conv[pt-1].fs*conv[pt].sc-conv[pt-1].sc*conv[pt].fs;
		sum -= conv[i].fs*conv[i+1].sc-conv[i].sc*conv[i+1].fs;
		pt--;
	}
	string ss;
	while(ans)ss += '0'+ans%10,ans/=10;
	reverse(ss.begin(),ss.end());
	cout<<(!ss.empty()?ss:"0");
}
