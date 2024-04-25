#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d\n",&n);
    while(scanf("%d",&n) != EOF){
        if(n == 1){
            printf("1\n");
            scanf("\n");
            continue;
        }
        vector<int> values;
        int times = 0;
        while(n>=10){
            for(int i = 9;i>=2;i--){
                if(n%i == 0){
                    values.push_back(i);
                    n/=i;
                    times = 0;
                    break;
                }
                times++;
            }
            if(times !=0) break;
        }
        // cout<<n<<endl;
        if(n !=1&&n<10)values.push_back(n);
        else {
            printf("-1\n");
            scanf("\n");
            continue;
        }
        sort(values.begin(),values.end());
        for(int i= 0;i<values.size();i++){
            printf("%d",values[i]);
        }
        printf("\n");
        scanf("\n");
    }
}