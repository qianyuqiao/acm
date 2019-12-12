### 有手就行算法
```
vector<int> dist(N+1, INT_MAX);
for (int i = 0; i < N; i++)
{
    for (vector<int> e: edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
        }
    }
}
```
