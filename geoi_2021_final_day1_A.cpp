#include<bits/stdc++.h>
#define ll int
using namespace std;
ll n,w1,w2,dp[502][502],ndp[502][502],ans,x;
int main()
{
	cin>>n>>w1>>w2;
	dp[0][0]=1;
	ndp[0][0]=1;
	while (n--)
	{
		cin>>x;
		for (int i=0; i<=w1; i++)
			for (int j=0; j<=w2; j++)
			{
				if (!dp[i][j])
					continue;
				if (i+x<=w1)
				{
//					cout<<x<<" "<<i+x<<" "<<j<<endl;
					ndp[i+x][j]=1;
				}
				if (j+x<=w2)
				{
//					cout<<x<<" "<<i+x<<" "<<j<<endl;
					ndp[i][j+x]=1;
				}
			}
		for (int i=0; i<=w1; i++)
			for (int j=0; j<=w2; j++)
				dp[i][j]=ndp[i][j];
	}
	for (int i=0; i<=w1; i++)
		for (int j=0; j<=w2; j++)
			if (dp[i][j])
				ans=max(ans,i+j);
	cout<<ans<<endl;
	return 0;
}
