#include <cstdio>
using namespace std;

#define ll long long

int main(){
	ll n,m;
	int q;
	scanf("%lld%lld%d",&n,&m,&q);
	int ans =0;
	for(int i = 0;i<q;i++){
		ll sx,sy,ex,ey,x,y;
		scanf("%lld%lld%lld%lld%lld%lld",&sx,&sy,&ex,&ey,&x,&y);
		if(sx==ex&&sy==ey){
			ans++;
			continue;
		}
		else{
			bool m1 = false,m2 = false;
			if(sx==x||sy==y)m1 = true;
			if(ex==x||ey==y)m2 = true;
			if(m1&&m2){
				ans++;
			}
		}
	}
	printf("%d",ans);
}
//int main(){
//	ll n,m,q;
//	scanf("%lld%lld%lld",&n,&m,&q);
//	int ans = 0;
//	for(ll i = 0;i<q;i++){
//		ll sx,sy,ex,ey,x,y;
//		scanf("%lld%lld%lld%lld%lld%lld",&sx,&sy,&ex,&ey,&x,&y);
//		if(sx==ex&&ex == x){
//			ans++;
//		}
//		else if(sy == ey&&sy == y){
//			ans++;
//		}
//		else if(sy==ey&&sx==ex){
//			ans++;
//		}
//	}
//	printf("%d",ans);
//	return 0;
//} 
