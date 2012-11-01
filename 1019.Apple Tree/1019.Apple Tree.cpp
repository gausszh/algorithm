// 1019.Apple Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

// Problem#: 1019
// Submission#: 665848
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
queue<int> bn;
int n,k,w[130],vis[143],d[130][250][2],lft[130][250][2],e[130][130];
int jj[130];
bool flag[130];
int m(int a,int b)
{
    if(a>b)
        return a;
    return b;
}
void dp(int g)
{
    if(vis[g]==1)
        return ;
    vis[g]=1;
    queue<int> tmp;
    int x,y,j=0,p,q,o;
    for (j=0;e[g][j]!=-1;j++)
    {
        o=e[g][j];
        if(vis[o]!=1)
        {
            tmp.push(o);
            flag[g]=false;                  //表明此点非末端
            dp(o);
        }       
    }
    if (flag[g])
    {
        for(int i=2;i<=k;i++)
            for(int z=0;z<2;z++)
                d[g][i][z]=w[g];
        d[g][1][0]=w[g];
    }
    else{
        x=tmp.front();
        tmp.pop();
        for(int i=0;i<=k;i++)
        {
            lft[x][i][0]=d[x][i][0];
            lft[x][i][1]=d[x][i][1];
        }
        while (!tmp.empty())
        {
            y=tmp.front();
            tmp.pop();
            for(p=0;p<=k;p++)
                for (q=0;q<=k;q++)
                    if (p+q<=k)
                    {
                        lft[y][q+p][1]=m(lft[y][q+p][1],lft[x][p][1]+d[y][q][1]);             //全都返回
                        lft[y][p+q][0]=m(m(lft[y][p+q][0],lft[x][p][1]+d[y][q][0]),m(lft[y][q+p][0],lft[x][p][0]+d[y][q][1]));  //不反,前反+现不返 || 前不返+现返
                    }
                    else break;
            x=y;
        }
        for(int i=2;i<=k+1;i++)
        {
            d[g][i][0]=lft[x][i-1][0]+w[g];
            d[g][i][1]=lft[x][i-2][1]+w[g];
        }
        d[g][1][0]=w[g];

    }
}
int main()
{
    int a,b;
    while (cin >>n)
    {
        memset(jj,0,sizeof(jj));
        memset(lft,0,sizeof(lft));
        memset(flag,true,sizeof(flag));
        memset(d,0,sizeof(d));
        memset(e,-1,sizeof(e));
        memset(vis,0,sizeof(vis));
        cin >>k;
        for(int i=1;i<=n;i++)
            cin >>w[i];
        for (int i=1;i<n;i++)
        {
            cin >>a>>b;
            e[a][jj[a]]=b;
            e[b][jj[b]]=a;
            jj[a]++;
            jj[b]++;
        }
        if(n==1 || k==0)
            cout <<w[1]<<endl;
        else
        {
            dp(1);
            cout <<d[1][k+1][0]<<endl;
        }
    }
    return 0;
}                                 
/*
6 3
2 5 3 6 1 4
1 2
1 3
1 4
2 5
2 6
 

 2 1 
 0 11
 1 2
 3 2
 0 1 2
 1 2
 1 3
 请按任意键继续. . .*/


/*

int dp(int i,int j,int cnd)			//i为节点，j为到此节点是还可以走多少步，cnd状态，1返回0不返回
{
	if(d[i][j][cnd]>=0)
		return d[i][j][cnd];
	//预处理，无论cnd是0还是1，都得计算节点i的儿子在返回的情形下的值
	int x,y,JD=1;
	if(vis[i]==0)
	while (e[i][JD]!=-1)
	{
		vis[i]=1;
		x=e[i][JD];
		JD++;
		for (int s=2;s<k-cnd;s++)			//
			d[x][s][1]=dp(x,s,1);
	}
	if(cnd==1)
	{
		JD=1;
		x=e[i][JD];
		for(int s=0;s<j-1;s++)											//cnd==1 返回
			lft[x][s][1]=d[x][s][1];
		JD++;
		int q,p;
		while (e[i][JD]!=-1)
		{
			y=e[i][JD];
			JD++;
			for (p=0;p<j-1;p++)
				for(q=0;q<j-1;q++)
					if (p+q<j-1)
						lft[y][q+p][1]=m(lft[y][q+p][1],lft[x][p][1]+d[y][q][1]);	
					else
						break;
			x=y;
		}
		return d[i][j][1]=lft[x][j-2][1]+fen[i];
	}
	if(cnd==0)							//不返回
	{
		JD=1;
		while (e[i][JD]!=-1)						//全不返
		{
			x=e[i][JD];
			JD++;
			for (int s=1;s<j;s++)			//
				d[x][s][0]=dp(x,s,0);
		}
		JD=1;
		x=e[i][JD];
		for(int s=0;s<j;s++)											//有一个返回
			lft[x][s][1]=d[x][s][1];

		for(int s=0;s<j;s++)												//不返回
			lft[x][s][0]=d[x][s][0];
		JD++;
		int q,p;
		while (e[i][JD]!=-1)
		{
			y=e[i][JD];
			JD++;
			for (p=0;p<j;p++)
				for(q=0;q<j;q++)
					if (p+q<j)
					{
						lft[y][q+p][1]=m(lft[y][q+p][1],lft[x][p][1]+d[y][q][1]);				//全都返回
						lft[y][p+q][0]=m(m(lft[y][p+q][0],lft[x][p][1]+d[y][q][0]),m(lft[y][q+p][0],lft[x][p][0]+d[y][q][1]));  //不反,前反+现不返 || 前不返+现返
					} 
					else
						break;
			x=y;
		}
		return d[i][j][0]=lft[x][j-1][0]+fen[i];
	}
}*/
