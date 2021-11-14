# data-structure-and-algorithm
用于自学，水平有限，欢迎指正。

2021-11-12 algorithm about graph

--------------Graph/-------------
1. 图的表示：邻接表(LGraph.h)和邻接矩阵(MGraph.h)
2. 图的遍历：DFS(DFS.h)与BFS(BFS.h)
3. 图的拓扑排序(TopSort.h)，时间复杂度为O(|V|+|E|)
4. 基于邻接表实现的单源最短路径算法
	4.1 对于有向无环图(DAG)，可使用DAGShortest.h中的算法，时间复杂度为O(|V|+|E|)
	4.2 Bellman Ford算法(bellman_ford.h)，时间复杂度为O(|V||E|)
	4.3 Dijkstra算法(Dijkstra.h)，时间复杂度为O((|V|+|E|)*log|V|)
5. 实现算法的过程中需要的一些数据结构，队列(Queue.h)和小顶堆(MinHeap.h)
