/**
	split(x, y, a)
		x 分裂之前Splay树的树根
		a 分裂之后前半部分的大小
		x,y分裂之后两棵树的树根
	join(x, y);
		x, y 合并之前两棵树的树根
		x 合并之后Splay树的树根
	getRank(x);
		x Splay树的节点
		节点在树中的排名
	split3(x, y, z, a, b);
		a, b 将树分为三部分，分别为[... a-1], [a, b], [b+1...]
		输出x,y,z分别为三部分的树根
	join3(x, y, z);
		x,y,z 三棵树的树根；将树x,y,z合并
		x 树的树根
*/

struct SplayTree {
	int nodeCnt, root, type[maxNodeCnt], parent[maxNodeCnt],
	childs[maxNodeCnt][2], size[maxNodeCnt],
	stack[maxNodeCnt], reversed[maxNodeCnt];
	
	void clear() {
		root = 0;
		size[0] = 0;
		nodeCnt = 1;
	}
	
	int malloc() {
		type[nodeCnt] = 2;
		childs[nodeCnt][0] = childs[nodeCnt][1] = 0;
		size[nodeCnt] = 1;
		reversed[nodeCnt] = 0;
		return nodeCnt++;
	}
	
	void update(int x) {
		// NOTICE: childs[x][i] == 0;
		if (reverse[x]) {
			swap(childs[x][0], childs[x][1];
			type[childs[x][0]] = 0;
			reversed[childs[x][0]] ^= 1;
			type[childs[x][1]] = 1;
			reversed[childs[x][1]] ^= 1;
			reversed[x] = 0;
		}
	}
	
	void rotate(int x) {
		int t = type[x],
			y = parent[x],
			z = child[x][1 - t];
		type[x] = type[y];
		parent[x] = parent[y];
		if (type[x] != 2) {
			childs[parent[x]][type[x]] = x;
		}
		type[y] = 1 - t;
		parent[y] = x;
		childs[x][1 - t] = y;
		if (z) {
			type[z] = t;
			parent[z] = y;
		}
		childs[y][t] = z;
		update(y);
	}
	
	void splay(int x) {
		int stackCnt = 0;
		stack[stackCnt++] = x;
		for (int i = x; type[i] != 2; i = parent[i]) {
			stack[stackCnt++] = parent[i];
		}
		for (int i = stackCnt - 1; i > -1; --i) {
			pass(stack[i]);
		}
		while (type[x] != 2) {
			int y = parent[x];
			if (type[x] == type[y]) {
				rotate(y);
			} else {
				rotate(x);
			}
			if (type[x] == 2) {
				break;
			}
			rotate(x);
		}
		update(x);
	}
	
	int find(int x, int rank) {
		while (true) {
			pass(x);
			if (size[childs[x][0] + 1 == rank) {
				break;
			}
			if (rank <= size[childs[x][0]]) {
				x = childs[x][0];
			} else {
				rank -= size[childs[x][0] + 1;
				x = childs[x][1];
			}
		}
		return x;
	}
	
	void split(int &x, int &y, int a) {
		// NOTICE: x, y != 0
		y = find(x, a + 1);
		splay(y);
		x = childs[y][0];
		type[x] = 2;
		childs[y][0] = 0;
		update(y);
	}
	
	void split3(int &x, int &y, int &z, int a, int b) {
		split(x, z, b);
		split(x, y, a - 1);
	}
	
	void join(int &x, int y) {
		// NOTICE x, y != 0
		x = find(x, size[x]);
		splay(x);
		childs[x][1] = y;
		type[y] = 1;
		parent[y] = x;
		update(x);
	}
	
	void join3(int &x, int y, int z) {
		join(y, z);
		join(x, y);
	}
	
	int getRank(int x) {
		splay(x);
		root = x;
		return size[child[x][0]];
	}
	
	void reverse(int a, int b) {
		int x, int y;
		split3(root, x, y, a + 1, b + 1);
		reversed[x] ^= 1;
		join3(root, x, y);
	}
};
	