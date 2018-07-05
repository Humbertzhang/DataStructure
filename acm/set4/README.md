# 二分法
https://vjudge.net/contest/236645
pswd:ccnuacm

二分法最常见的应用是使最大值最小 和 使最小值最大 <br>

这种题的思路就是，找出一个上界和下界，之后通过迭代的二分法配合check函数来进行二分查找解空间。
check函数根据题目的不同而不同，如A题和C题就比较典型

E题是对二分查找法进行了一些修改。虽然不能直接用二分查找找到准确解，但是可以利用二分查找的特性快速逼近解所在的地方，再根据题目要求找到差的绝对值最小的地方.

B,D较难，还未解出

A题: http://poj.org/problem?id=3273
C题: http://poj.org/problem?id=3122
E题: hihocoder 1514题
