// Allocate Minimum Pages
#include <stdio.h>

int max(int a,int b){ return a>b?a:b; }

int isPossible(int arr[],int n,int m,int limit){
    int students=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>limit) return 0;
        if(sum+arr[i]>limit){
            students++; sum=arr[i];
        } else sum+=arr[i];
    }
    return students<=m;
}

int main(){
    int n,m; scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int low=0, high=0;
    for(int i=0;i<n;i++){
        high+=arr[i];
        low=max(low,arr[i]);
    }

    int ans=high;
    while(low<=high){
        int mid=(low+high)/2;
        if(isPossible(arr,n,m,mid)){
            ans=mid; high=mid-1;
        } else low=mid+1;
    }
    printf("%d",ans);
}
