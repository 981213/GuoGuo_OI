//
//	ID: y0rkl1u
//	PROG: P1401 -- [bonism]TreeCount
//	LANG: C++
//	DATE: 06.12.2015
//	NOTE: SPFA, Enum
//

#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_E = 2000000, MAX_V = 1000;
int V, E, E_cnt;
int Last_edge[MAX_V+10], Weight[MAX_E+10];
int Next_edge[MAX_E+10], To[MAX_E+10], From[MAX_E+10];
int Dist[MAX_V+10], F[MAX_V+10];
bool Vis[MAX_V+10];

inline void AddEdge(int u, int v, int w)
{
	E_cnt++;
	From[E_cnt] = u;
	To[E_cnt] = v;
	Weight[E_cnt] = w;
	Next_edge[E_cnt] = Last_edge[u];
	Last_edge[u] = E_cnt;
}

queue<int> Q;
void SPFA(int src, int *dist)
{
	memset(Vis, 0, sizeof(Vis));
	memset(dist, 60, sizeof(int)*(V+1));
	dist[src] = 0;
	Vis[src] = true;
	Q.push(src);
	while (!Q.empty()) { 
		int u = Q.front(); Q.pop();
		Vis[u] = false;
		for (int e = Last_edge[u]; e; e = Next_edge[e]) {
			int v = To[e];
			if (dist[v] > dist[u] + Weight[e]) {
				dist[v] = dist[u] + Weight[e];
				if (!Vis[v]) {
					Vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
}

inline void P1401()
{
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		AddEdge(u, v, w);
		AddEdge(v, u, w);
	}
	SPFA(1, Dist);
	for (int e = 1; e <= E_cnt; e++) {
		int u = From[e], v = To[e];
		if (Weight[e] + Dist[u] == Dist[v] && v != 1) {
			F[v]++;
		}
	}

	static const long long MODULUS = 2147483647LL;
	long long ans = 1;
	for (int u = 2; u <= V; u++) {
		ans = ans * F[u];
		if (ans >= MODULUS) ans %= MODULUS;
	}
	printf("%lld\n", ans);
}

int main()
{
	P1401();
	return 0;
}

