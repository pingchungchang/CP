#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    scanf("%d %d\n",&n,&m);
    for(int i = 0;i<n;i++){
        vector<int> v1(m,0);
        vector<int> v2(m,0);
        int k = 0;
        for(int j = 0;j<m-1;j++){
            scanf("%d ",&k);
            v1[j] = k;
        }
        scanf("%d\n",&k);
        v1[v1.size()-1] = k;
        for(int j = 0;j<m-1;j++){
            scanf("%d ",&k);
            v2[j] = k;
        }
        scanf("%d\n",&k); 
        v2[v2.size()-1] = k;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int p1=0,p2=0;
        int ans = 0;
        while(p1<m&&p2<m){
            if(v1[p1]>v2[p2])p2++;
            else if(v1[p1] == v2[p2]){
                ans++;
                p1++;
            }
            else p1++;
        }
        printf("%d\n",ans);
    }
}