 0;
	if (edge[u].size()==1){
		f[u][0] = f[u][1] = 0;
		return 1;
	}
	for (int v: edge[u]) if (v!=p){
		int vleaf = dfs(v,u);
		for (int i = uleaf; i >= 0; i--) for (int j = vleaf; j >= 0; j--){
			f[u][i+j] = max(f[u][i+j],f[u][i]+f[v][j]+i*j);
		} 
		uleaf += vleaf;
		int tmp = 0;
		for (int i = 0; i <= vleaf; i++) tmp = max(tmp,f[v][i]+i);
		cur += tmp;
	}
	f[u][1] = max(f[u][1],cur);