# data-structure-and-algorithm
*用于自学，水平有限，欢迎指正。*

- Graph

1. 图的表示：邻接表(LGraph.h)和邻接矩阵(MGraph.h)
2. 图的遍历：DFS(DFS.h)与BFS(BFS.h)
3. 图的拓扑排序(TopSort.h)，时间复杂度为O(|V|+|E|)
4. 基于邻接表实现的单源最短路径算法
	4.1 对于有向无环图(DAG)，可使用DAGShortest.h中的算法，时间复杂度为O(|V|+|E|)
	4.2 Bellman Ford算法(bellman_ford.h)，时间复杂度为O(|V||E|)，图中可以存在负权重的边，但不能存在负值圈。
	4.3 Dijkstra算法(Dijkstra.h)，时间复杂度为O((|V|+|E|)*log|V|)，图中任意边的权重为非负。
5. 基于邻接矩阵实现的多源最短路算法
	5.1 Floyd算法(Floyd.h)，时间复杂度为O(|V|^3)
	5.2 Johnson算法(Johnson.h)，时间复杂度为O(|V||E|log|V|)，适用于稀疏图，可以有负权重，但不能有负值圈。
6. 实现算法的过程中需要的一些数据结构，队列(Queue.h)和小顶堆(MinHeap.h)
7. 最小生成树
	7.1 Prim算法(Prim.h)
	7.2 Kruskal算法(Kruskal.h)

- Tree

1. 树的表示: Tree.h
2. 二叉搜索树的通用操作，不包含插入和删除操作（因为插入和删除对于普通二叉搜索树和平衡二叉搜索树之间有差异）: BasicOperate.h
3. 二叉搜索树的插入和删除: BST.h
4. 红黑树的插入和删除: RBT.h
5. 线段树，用于区间查询与区间修改: segementTree.cpp
