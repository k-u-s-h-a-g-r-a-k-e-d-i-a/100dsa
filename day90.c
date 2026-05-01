// Painter Partition Problem
#include <stdio.h>

int isPossible(int arr[],int n,int k,long long limit){
    int painters=1;
    long long sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>limit) return 0;
        if(sum+arr[i]>limit){
            painters++; sum=arr[i];
        } else sum+=arr[i];
    }
    return painters<=k;
}

int main(){
    int n,k; scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    long long low=0, high=0;
    for(int i=0;i<n;i++){
        high+=arr[i];
        if(arr[i]>low) low=arr[i];
    }

    long long ans=high;
    while(low<=high){
        long long mid=(low+high)/2;
        if(isPossible(arr,n,k,mid)){
            ans=mid; high=mid-1;
        } else low=mid+1;
    }
    printf("%lld",ans);
}
