int N, M, K;
cin>>N>>M>>K;
lakes[N][M];
for (int i = 0; i<N; i++) {
	for (int j = 0; j<M; j++) {
		lakes[i][j] = true;
	}
}
int x, y;
for (int i = 0; i<K; i++) {
	cin>>x>>y;
	lake[x-1][y-1] = false;
}

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

typedef pair<int, int> point;
queue<point> visited;
