#include<bits/stdc++.h>
using namespace std;
#define MAXC 1000
char A[MAXC],B[MAXC];
int lenA,lenB;
int dp[MAXC][MAXC];
bool visited[MAXC][MAXC];
/// Length of longest common subsequence
int calcLCS(int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0') return 0;
	if(visited[i][j])return dp[i][j];

	int ans=0;
	if(A[i]==B[j]) ans=1+calcLCS(i+1,j+1);
	else
	{
		int val1=calcLCS(i+1,j);
		int val2=calcLCS(i,j+1);
		ans=max(val1,val2);
	}
	visited[i][j]=1;
	dp[i][j]=ans;
	return dp[i][j];
}
///the longest common subsequence
string anss;
void printLCS(int i,int j)
{
    if(A[i]=='\0' || B[i]=='\0')
    {
        cout<<anss<<endl;
        return ;
    }
    if(A[i]==B[i])
    {
        anss+=A[i];
        printLCS(i+1,j+1);
    }
    else
    {
        if(dp[i][j+1]>dp[i+1][j])
            printLCS(i,j+1);
        else
            printLCS(i+1,j);
    }
}

/// print all answer
string ansss;
void printAll(int i,int j)
{
	if(A[i]=='\0' or B[j]=='\0'){
		cout<<ansss<<endl;
		return;
	}
	if(A[i]==B[j]){
		ansss+=A[i];
		printAll(i+1,j+1);
		ansss.erase(ansss.end()-1); //Delete last character, deletese after printing

	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(i,j+1);
		else
		{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}
int main() {
	scanf("%s%s",A,B);
	lenA=strlen(A);
	lenB=strlen(B);
	printf("%d\n",calcLCS(0,0));
	printAll(0,0);
	return 0;

}
