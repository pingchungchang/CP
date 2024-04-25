#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll gcd(ll a,ll b){
	if(a>b)swap(a,b);
	while(b != 0){
		a%=b;
		swap(a,b);
	}
	return a;
}
void prll(ll y,ll m,ll d){
	string sy,sm,sd;
	sy = to_string(y);
	sm = to_string(m);
	sd = to_string(d);
	while(sy.size()!= 4)sy = '0'+sy;
	while(sm.size()!=2)sm = '0'+sm;
	while(sd.size()!=2)sd = '0'+sd;
	cout<<sy<<'/'<<sm<<'/'<<sd;
}
bool isleap(int n){
	if(n%400 == 0)return true;
	if(n%100 == 0)return false;
	if(n%4 == 0)return true;
	return false;
}
int main(){
	ll n;
	cin>>n;
	ll now = 1;
	for(ll i = 0;i<n;i++){
		ll k;
		cin>>k;
		now = now*k/gcd(now,k);
	}
	stringstream ss;
	ss.clear();
	string s;
	cin>>s;
	for(ll i = 0;i<s.size();i++)if(s[i] == '/')s[i] = ' ';
	ss<<s;
	ll y,m,d;
	ss>>y>>m>>d;
	for(ll i = 1;i<m;i++){
		if(i == 1||i == 3||i == 5||i == 7||i == 8||i == 10||i==12)now += 31;
		else if(i != 2)now+= 30;
		else if(y%4 == 0&&y%100 !=0)now+= 29;
		else if(y%400 == 0)now += 29;
		else now += 28;
	}
	now += d;
	while(true){
		if(isleap(y) == false&&now>365)now -= 365;
		else if(now>366)now -= 366;
		else break;
		y++;
	}
	for(int i = 1;i<=12;i++){
		if(i == 1||i == 3||i == 5||i == 7||i == 8||i == 10||i==12){
			if(now>31)now -= 31;
			else{
				prll(y,i,now);
				return 0;
			}
		}
		else if(i != 2){
			if(now>30)now -= 30;
			else{
				prll(y,i,now);
				return 0;
			}
		}
		else if(isleap(y) == false){
			if(now>28)now -= 28;
			else{
				prll(y,i,now);
				return 0;
			}
		}
		else{
			if(now>29)now -= 29;
			else {
				prll(y,i,now);
				return 0;
			}
		}

	}
	
}
