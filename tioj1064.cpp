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
#pragma GCC optimize("O3")
typedef __int128_t i128;//p1 = 1004535809, p2 = 2013265921
const ll mod1 = 11004535809,mod2 = 2013265921;
const ll PI1 = 11004535809-1,PI2 = 2013265921-1;
const ll G1 = 3,G2 = 31;
const ll mxn = 1<<21;
bool done[mxn];
ll inverse(ll a,ll m);
ll mult(ll a,ll b,ll m){
	if(m == 0){
		ll re = 0;
		while(b != 0){
			if(b&1)re += a;
			a += a;
			if(a>mod1)a -= mod1;
			if(re>mod1)re -= mod1;
			b>>=1;
		}
		return re;
	}
	if(m == 1){
		ll re = 0;
		while(b != 0){
			if(b&1)re += a;
			a += a;
			if(a>mod2)a -= mod2;
			if(re>mod2)re -= mod2;
			b>>=1;
		}
		return re;
	}
}
ll pw(ll a,ll b,ll m){
	if(b<0)return pw(inverse(a,m),-b,m);
	ll now = 1;
	while(b!= 0){
		if(b&1)now = mult(now,a,m);
		a = mult(a,a,m);
		cout<<now<<' '<<a<<endl;
		b>>=1;
	}
	return now;
}
ll inverse(ll a,ll m){
	if(m == 0)return pw(a,mod1-2,0);
	else return pw(a,mod2-2,1);
}
void NTT(vector<ll>&F,ll inv,bool m){
	int n = F.size();
	fill(done,done+n,false);
	int k = n,b = 0;
	for(;k!= 0;k>>=1,b++);
	b--;
	for(int i = 0;i<n;i++){
		if(done[i])continue;
		int re = 0,tmp = i;
		for(int j = 0;j<b;j++){
			re<<=1;
			if(tmp&1)re^=1;
			tmp>>=1;
		}
		done[re] = done[i] = true;
		swap(F[re],F[i]);
	}
	
	for(int step = 1;step<n;step<<=1){
		for(int i = 0;i<n;i+= step<<1){
			ll now = 1;
			if(m == 0){
				ll theta = inv*PI1/(step*2);
				ll w = pw(G1,theta,m);
				for(int j = 0;j<step;j++){
					ll a = F[i+j],b = F[i+j+step]*now%mod1;
					F[i+j] = (a+b>=mod1?a+b-mod1:a+b);
					F[i+j+step] = (a-b<0?a-b+mod1:a-b);
					now = now*w%mod1;
				}
			}
			else{
				ll theta = inv*PI2/(step*2);
				ll w = pw(G2,theta,m);
				for(int j = 0;j<step;j++){
					ll a = F[i+j],b = F[i+j+step]*now%mod2;
					F[i+j] = (a+b>=mod2?a+b-mod2:a+b);
					F[i+j+step] = (a-b<0?a-b+mod2:a-b);
					now = now*w%mod2;
				}				
			}
		}
	}
	if(inv == -1){
		ll invn = pw(n,-1,m);
		for(auto &i:F){
			i = i*invn;
			if(m == 0)i%=mod1;
			else i %= mod2;
		}
	}
	return;
}
string tostring(ll a){
	string re;
	if(a == 0)return "0";
	while(a != 0){
		re += '0'+a%10;
		a /= 10;
	}
	reverse(_all(re));
	return re;
}
ll toll(string s){
	ll re = 0;
	for(auto &i:s){
		re *= 10;
		re += i-'0';
	}
	return re;
}
void print(ll t){
	cout<<tostring(t);
}
int main(){
//	cout<<mult(9,9,0);return 0;
	cout<<2LL*inverse(2,0)%mod1;
	return 0;
	int len = 6;
	string a,b;
	cin>>a>>b;
	reverse(_all(a));
	reverse(_all(b));
	while(a.size()%len != 0)a+='0';
	while(b.size()%len != 0)b += '0';
	int sz = (max(a.size(),b.size()))/len;
	vector<ll> A(sz*2,0),B(sz*2,0);
	for(int i = 0;i<a.size();i+=len){
		string tmp = a.substr(i,len);
		reverse(_all(tmp));
		A[i/len] = (ll)stoi(tmp);
	}
	for(int i = 0;i<b.size();i+=len){
		string tmp = b.substr(i,len);
		reverse(_all(tmp));
		B[i/len] = (ll)stoi(tmp);
	}
	int tmp = 1;
	sz = A.size();
	while(tmp<sz)tmp<<=1;
	while(A.size()<tmp)A.push_back(0);
	while(B.size()<tmp)B.push_back(0);
	auto A1 = A,B1 = B;
	NTT(A1,1,0);
	NTT(B1,1,0);
	for(int i = 0;i<A1.size();i++)A1[i]= A1[i]*B1[i]%mod1;
	NTT(A1,-1,0);
	auto A2 = A,B2 = B;
	NTT(A2,1,1);
	NTT(B2,1,1);
	for(int i= 0;i<A2.size();i++)A2[i] = A2[i]*B2[i]%mod2;
	NTT(A2,-1,1);
	for(auto &i:A)cout<<i<<' ';cout<<endl;
	ll ts[] = {pw(mod2%mod1,-1,0),pw(mod1%mod2,-1,1)};
	for(int i = 0;i<A.size();i++){
		A[i] = A[i]*ts[0]%mod1*(mod2%mod1)%mod1+A[i]*ts[1]%mod2*(mod1%mod2)%mod2;
	}
	ll t = 1;
	for(int i = 0;i<len;i++)t*=10;
	ll add = 0;
	for(auto &i:ts)cout<<i<<endl;return 0;
	for(int i = 0;i<A.size();i++){
		ll vals = A[i]+add;
		A[i] = vals%t;
		add = vals/t;
	}
	bool flag = false;
	if(add != 0){
		flag = true;
		cout<<add;
	}
	for(int i =A.size()-1;i>=0;i--){
		if(A[i] == 0&&flag == false)continue;
		string tmp = tostring(A[i]);
		while(tmp.size()<len)tmp = "0"+tmp;
		if(flag == false)cout<<stoll(tmp);
		else cout<<tmp;
		flag = true;
	}
	return 0;
}

