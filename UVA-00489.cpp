#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == -1)return 0;
        printf("Round %d:\n",n);
        char ans[100];
        char guess[100];
        scanf("%s\n%s",ans,guess);
        int arr[26] = {0};
        int totals = 0;
        for(int i =0;i<strlen(ans);i++){
            if(arr[ans[i]-'a'] == 0)totals++;
            arr[ans[i]-'a'] = 1;
        }
        int wrongs = 0;
        for(int i =0;i<strlen(guess);i++){
            if(arr[guess[i]-'a'] == 0){
                arr[guess[i]-'a'] = -1;
                wrongs++;
            }
            else if(arr[guess[i]-'a'] == 1){
                arr[guess[i]-'a'] = -1;
                totals--;
            }
            if(totals == 0)break;
            if(wrongs == 7)break;
        }
        if(totals == 0)printf("You win.\n");
        else if(wrongs == 7)printf("You lose.\n");
        else printf("You chickened out.\n");
    }
}