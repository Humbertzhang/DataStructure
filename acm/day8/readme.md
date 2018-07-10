

## 用二维vector作为临界表(无边权)
### 有向边
vector <int> E[N];
for(){
	input u, v; // 一条u -> v的边
	E[u].push_back(v)
}

for(i){
	cout << i;
	for(int j = 0; j < E[i].size(); j++){
		cout << "->" << E[i][j];
	}	 
}

### 无向边
只需在push_back() 时两个节点都push_back() 即可


## 有边权
读入from, to, value
使用struct
struct {
	int to, time;	
}
vector<node> E[N];
scnaf(u, v, time)
node x;
x.to = v;
x.time= time;
E[u].push_back(x);


