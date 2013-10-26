#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define mp make_pair
#define A first
#define B second
#define pb push_back
int main()
{
    ll t;
    //freopen("c2.in","r",stdin);
    //freopen("out.txt","wt",stdout);
    scanf("%lld",&t);
    while(t--)
    {
    ll n;
    
    scanf("%lld",&n);
    
    vector<ll>a(n);
    vector<pair<int,int> >sum(n);
    scanf("%lld",&a[0]);
    sum[0]=mp(a[0],1);
    int count=0;
	for(ll i=1;i<n;i++)
    {
	 	   scanf("%lld",&a[i]);
	 	   sum[i]=mp(sum[i-1].first+a[i],i+1);
    }
    sum.pb(mp(0,0));
    sort(sum.begin(),sum.end());
    int i=0,j=0;
    while(i<=n && j<=n && i>-1 && j>-1)
    {
	 		   if(sum[i].A-sum[j].A <47)
	 		   i++;
	 		   if(sum[i].A-sum[j].A >47)
	 		   j++;
	 		   if(sum[i].A-sum[j].A==47)
	 		   {
			   	   int ie,je;
			   	   for(ie=i;sum[ie].A==sum[i].A;ie++);
			   	   
			   	   for(je=j;sum[je].A==sum[j].A;je++);
			   	   
			   	   
		           while(i<ie && j<je )
				   {
				   			  if(sum[i].B>sum[j].B)
								 {count+=(ie-i);j++;}
						      else
						         {i++;}
						         
                   }
                   
                   i=ie;
                   j=je;
	          }
    }
							   		  
    printf("%d\n",count);

    
    }
    //system("pause");
}
