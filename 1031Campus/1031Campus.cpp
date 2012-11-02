// Problem#: 1031
// Submission#: 456856
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <cstdio>

using namespace std;

struct Edge                     //边
{
    int end, dist;
};
struct Node
{
    vector< Edge > next;
    int d;                          //当前距离
};

Node n[200]; 
int s, t;
int ns, es;

struct cmp 
{
    bool operator ()(const int& a, const int& b) const 
    {
    return n[a].d > n[b].d;
    }
};
priority_queue< int, vector< int >, cmp > pq;

bool Init()
{
    int i, tempi;
    map< string, int > sim;             //转换，字符串与数字，映射
    string p1, p2;
    Edge temp;
    for(i=0; i<200; i++)
    {
        n[i].next.clear();
    }

    scanf("%d", &es);                   //边的数量
    for(i=0; i<es; i++)
    {   
        cin >> p1 >> p2 >> temp.dist;
        if(sim.find(p1) == sim.end())
        {
            tempi = sim.size();
            sim[p1] = tempi;
        }
        if(sim.find(p2) == sim.end())
        {   
            tempi = sim.size();
            sim[p2] = tempi;
        }
        temp.end = sim[p2];
        n[sim[p1]].next.push_back(temp);                //顶点
        temp.end = sim[p1];
        n[sim[p2]].next.push_back(temp);
    }
    cin >> p1 >> p2;
    if(p1 == p2)
    {
        s = t;
        return true;
    }
    if(sim.find(p1) == sim.end() || sim.find(p2) == sim.end())
    return false;
    s = sim[p1];
    t = sim[p2];
    ns = sim.size();                //点数
    while(!pq.empty())
    {
        pq.pop();
    }
    return true;
}

void Init_Single_Source()
{
    int i;
    for(i=0; i<ns; i++)
    {
        n[i].d = 100000000;
    }
    n[s].d = 0;
}

void Dijkstra()
{
    Init_Single_Source();
    int i, u;
    for(i=0; i<ns; i++)
    {
        pq.push(i);
    }

    vector< Edge >::iterator iter, end;
    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        end = n[u].next.end();
        for(iter=n[u].next.begin(); iter!=end; iter++)
        {
            int temp = n[u].d + iter->dist;
            if(n[iter->end].d > temp)
            {
                n[iter->end].d = temp;
                pq.push(iter->end);
            }
        }
    }
}

int main() 
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        if(!Init())
            printf("-1\n");
        else if(s == t)
            printf("0\n");
            else
            {
                Dijkstra();
                if(n[t].d < 100000000)
                    printf("%d\n", n[t].d);
                else
                    printf("-1\n");
            }
    }
return 0;
}
                                 
