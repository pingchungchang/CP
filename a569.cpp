#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
bool primes[(ll)1e7+1];
void solve(){
	vector<ll> v;
	s += ' ';
	string k;
	for(int i = 0;i<s.size();i++){
		if(s[i] == ' '){
			if(primes[stoll(k)] == true){
				v.push_back(stoll(k));
			}
			else v.push_back(0);
			k = "";
		}
		else{
			k += s[i];
		}
	}
	ll ans = v[0];
	vector<ll> val(v.size(),0);
	val[0] = v[0];
	for(int i = 1;i<v.size();i++){
		if(v[i]>v[i-1]){
			val[i]= v[i]+val[i-1];
		}
		else{
			val[i] = v[i];
		}
		ans = max(ans,val[i]);
	}
	cout<<ans<<'\n';
	
}
int main(){
	memset(primes,true,sizeof(primes));
	primes[1] = false;
	primes[0] = false;
	for(int i = 2;i<=1e7;i++){
		if(primes[i] == true){
			for(int j = 2*i;j<=1e7;j+=i){
				primes[j] = false;
			}
		}
	}
	while(getline(cin,s)){
		solve();
	}
}

