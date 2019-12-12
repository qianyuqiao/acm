### 有手就行算法
```
for (int i = 0; i < N; i++)
{
    for (vector<int> e: edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != -1 && dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
        }
    }
}
```
