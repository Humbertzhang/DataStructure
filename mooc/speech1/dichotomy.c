/*
讨论1.5 分析“二分法”老师参与
    查找算法中的“二分法”是这样定义的：
    给定N个从小到大排好序的整数序列List[]，以及某待查找整数X，我们的目标是找到X在List中的下标。即若有List[i]=X，则返回i；否则返回-1表示没有找到。
    二分法是先找到序列的中点List[M]，与X进行比较，若相等则返回中点下标；否则，若List[M]>X，则在左边的子系列中查找X；若List[M]<X，则在右边的子系列中查找X。
    试写出算法的伪码描述，并分析最坏、最好情况下的时间、空间复杂度。
*/

int dichotomy(int * L, int X)
{
	M = len(L)/2;
	if(L[M] == X)
		return M;
	else if(L[M] < X)
		return dichotomy(L[M:-1])
	else if(L[M] > X)
		return dichotomy(L[0:M])
}

最好时间复杂度：O(1),最坏时间复杂度：O(logN)
