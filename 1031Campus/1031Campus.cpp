// 1031Campus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}/*
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <queue>
#include <map>
#include <cstdio>

using namespace std;

struct Edge						//边
{
	int end, dist;
};
struct Node
{
	vector< Edge > next;
	int d;							//当前距离
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
	map< string, int > sim;				//转换，字符串与数字，映射
	string p1, p2;
	Edge temp;
	for(i=0; i<200; i++)
	{
		n[i].next.clear();
	}

	scanf("%d", &es);					//边的数量
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
		n[sim[p1]].next.push_back(temp);				//顶点
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
	ns = sim.size();				//点数
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
system("pause");
return 0;
}*/


#include <iostream>
#include <map>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

struct list{
	int n,len;				//图的邻接表示法，n是另一端点，len是边长度
};

struct point{					//点
	vector<list>L;
	int dis;					//距离
	int n;				//邻接表的头
	int hadd;			//放入堆后，在堆中的位置
};
point p[2000];
//heap堆
class heap{
public:
	point h[2000];
	bool insert_color[2000];
	bool pop_color[2000];
	int shuchu;
	int n;				//记录堆的位置数
	list t;
	heap();
	vector<list>::iterator it;
	void insert(point &x);
	point pop_heap();
};
heap::heap()
{
	n=0;
	for(int i=0;i<=2000;i++)
	{
		pop_color[i]=false;
		insert_color[i]=false;
	}
}
void heap::insert(point &x)
{
	int t=++n;
	while(t!=1 && x.dis<h[t/2].dis)
	{
		h[t]=h[t/2];
		h[t].hadd=t;
		t=t/2;
	}
	x.hadd=t;
	insert_color[x.n]=true;
	h[t]=x;
	h[t].hadd=t;
	
}
point heap::pop_heap()
{
	point item,tmp;
	item=h[1];
	pop_color[item.n]=true;
	tmp=h[n--];
	int parent=1,child=2;
	while(child<=n)
	{
		if(child<n && (h[child].dis>h[child+1].dis))
			child++;
		if(tmp.dis<=h[child].dis)
			break;
		h[parent]=h[child];
		h[parent].hadd=parent;
		p[h[parent].n].hadd=parent;
		parent=child;
		child*=2;
	}
	h[parent]=tmp;
	h[parent].hadd=parent;
	p[h[parent].n].hadd=parent;
	shuchu=item.dis;
	for(it=item.L.begin();it!=item.L.end();it++)
	{
		if(pop_color[it->n])
			continue;
		if(p[it->n].dis>item.dis+it->len)
			p[it->n].dis=item.dis+it->len;
		if(insert_color[it->n])
			h[p[it->n].hadd].dis=p[it->n].dis;
		else
		{
			insert(p[it->n]);
			insert_color[it->n]=true;
		}
	}
	return item;
}
int main()
{
	int qi,i,zh;			//边的起点终点
	int tempi;
	list list_tmp;
	point point_tmp;
	int cases,bian;
	string p1,p2;
	scanf("%d",&cases);
	while(cases--)
	{	
		heap d;
		map<string,int>zhuan;
		//for(i=0;i<2000;i++)
		//	p[i].L.clear();

		scanf("%d",&bian);
		while(bian--)
		{
			cin >> p1 >> p2>>list_tmp.len;
			if( zhuan.find(p1) == zhuan.end())
			{
				tempi = zhuan.size();
				zhuan[p1] = tempi;
			}
			if(zhuan.find(p2) == zhuan.end())
			{	
				tempi = zhuan.size();
				zhuan[p2] = tempi;
			}
			qi=zhuan[p1]+1;
			zh=zhuan[p2]+1;
			list_tmp.n = zh;
			p[qi].n=qi;
			p[qi].dis=10000;
			p[qi].L.push_back(list_tmp);									//顶点
			list_tmp.n = qi;
			p[zh].n=zh;
			p[zh].dis=10000;
			p[zh].L.push_back(list_tmp);
		}
		cin >>p1>>p2;
		if(zhuan.find(p1)==zhuan.end() || zhuan.find(p2)==zhuan.end())
		{
			if(p1!=p2)
			{
				printf("-1\n");
				continue;
			}
		}
		if(p1==p2)
		{
			printf("0\n");
			continue;
		}
		int b,e;			//寻找路径的begin，end
		b=zhuan[p1]+1;
		e=zhuan[p2]+1;
		p[b].dis=0;
		d.pop_color[b]=true;
		vector<list>::iterator iter;
		for(iter=p[b].L.begin();iter!=p[b].L.end();iter++)
		{
			p[iter->n].dis=iter->len;
			d.insert(p[iter->n]);
		}
		while(d.pop_heap().n!=e)
		{
			;
		}
		printf("%d\n",d.shuchu);
	}
	return 0;
}

