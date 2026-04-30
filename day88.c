// Aggressive Cows
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){ return (*(int*)a - *(int*)b); }

int canPlace(int stalls[], int n, int cows, int dist){
    int count = 1, last = stalls[0];
    for(int i=1;i<n;i++){
        if(stalls[i] - last >= dist){
            count++;
            last = stalls[i];
        }
        if(count >= cows) return 1;
    }
    return 0;
}

int main(){
    int n, cows;
    scanf("%d %d",&n,&cows);
    int stalls[n];
    for(int i=0;i<n;i++) scanf("%d",&stalls[i]);

    qsort(stalls,n,sizeof(int),cmp);

    int low=1, high=stalls[n-1]-stalls[0], ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(canPlace(stalls,n,cows,mid)){
            ans=mid; low=mid+1;
        } else high=mid-1;
    }
    printf("%d",ans);
}
