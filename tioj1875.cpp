#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n;
    while(cin>>n){
        if(n>6e8){
            cout<<n-1<<'\n';
            continue;
        }
        set<ll>st;
        ll tmp = n;
        bool flag = true;
        while(flag){
//        	cout<<n<<endl;
        	flag = false;
        	for(ll i = 2;i*i<=n;i++){
        		if(n%i == 0){
        			flag = true;
        			st.insert(i);
        			n/=i;
        			break;
				}
			}
		}
		if(n != 1)st.insert(n);
		for(auto i:st){
			tmp = tmp*(i-1)/i;
		}
		cout<<tmp<<'\n';
    }
}
