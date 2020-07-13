#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define inf 99999


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int> data(n);
        unordered_map<int,int> mp;
        forz(n) cin>>data[i],mp[data[i]]=i;

        int count = n-1;
        int j=0;
        int sum=0;
        
        while(count>0){
            j++;
            int index;
            for(int i=j;i<n;i++){
                if(data[i]==j){
                    index = i;
                    break;
                }
            }
            for(int i=index;i>=j;i--){
                if((data[i]<data[i-1]) && count>0){
                    int temp = data[i];
                    data[i] = data[i-1];
                    data[i-1] = temp;
                    count--;
                }else{
                    break;
                }
                
            }
            int l=1;
            for(int x:data){
                if(x != l++){
                    break;
                }
                
            }
            if(l == n+1){
                count = 0;
            }
        }
        for(int x:data){
            cout<<x<<" ";
        }
        cout<<'\n';
    }

    return 0;
}