void dijkstra()
{
	memset(dis, 0x3F, sizeof(dis));
	memset(vis, false, sizeof(vis));
	dis[s] = 0;
	
	for (int i = 0; i < n && !vis[t]; ++i)
	{
		int marker = s, amin = INF;
		for (int j = 0; j < n; ++j) if (!vis[j])
		{
			if (dis[j] < amin) {
				marker = j;
				amin = dis[j];
			}
		}
		vis[marker] = true;
		for (int j = 0; j < n; ++j) if (!vis[j])
			dis[j] = min(dis[j], dis[marker] + path[marker][j]);
	}
}