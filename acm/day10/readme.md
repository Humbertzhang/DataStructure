https://vjudge.net/contest/237513

# BFS
应用场景: 查找最短路径
+ 如:给一个整数x， 可对x + a, x * b, x/2等， 问你几步可以变成y
把x 看做一个节点，把他操作的三个当作跟他相邻的点，因此可以用BFS来查找

+ 网格图:问从一个点出发到另一个点最短路径多少

queue q;
q.push(初始节点)
while(!q.empty()){
	q.front()
	q.pop()
	for(遍历相邻节点){
		检查
		q.push(t)
		标记访问过	
	}	
}



DFS : 剪枝
