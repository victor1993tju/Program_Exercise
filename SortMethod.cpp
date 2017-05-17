// http://www.cnblogs.com/eniac12/p/5329396.html 
#include <stdio.h>

void swap(int *data, int i, int j)
{
	int temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}
//No.1 bubble sort
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
//每次从数组的最后开始比较相邻元素，将小元素放上面，遍历一次之后，最小值到达data[0],第二次遍历，第二小的值到达data[1].
void BubbleSort(int * data,int length)// int * data 和int data[] 是一样的，数组作为形参传递的是首地址
{
	for (int i = 1; i < length; i++)//从1开始循环，因为需要比较的次数比长度少一次
	{
		for (int j = length-1; j >= i; j--)// j 从后往前移动，i作为边界条件，
		{
			if (data[j]<data[j-1])
			{
				swap(data, j, j - 1);
			}
		}
	}
	
}
//No.2 简单选择排序
//和冒泡采用的交换法不同，每一轮选出最小的元素放在数组的最前面。
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定


void SelectSort(int * data, int length)
{
	for (int i = 0; i < length; i++)
	{
		int min = i;//初始化 i为最小值的下标
		for (int j = i+1; j < length;j++ )//依次比较后面的数值哪个最小，
		{
			if (data[j]<data[min])
			{
				min = j;
			}
		}
		if (i!=min)//
		{
			swap(data, min, i);
		}
	}
}
//No.3 直接插入排序
//和抓扑克牌的时候一张一张的放牌道理一样
// 分类 ------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定
void InsertSort(int data[], int length)
{
	for (int i = 1; i < length; i++)//从第二个元素开始，默认第一个元素是有序数列
	{
		if (data[i]<data[i-1])//如果当前元素比上一个大，则跳过插入，反之，把该值赋给哨兵，让其去寻找合适的位置
		{
			int pointer = data[i];//存储需要插入的数据，因为它原本的位置可能会被覆盖了
			int j;//用于寻找位置
			for (j = i-1; data[j]>pointer; j--)
			{
				data[j + 1] = data[j];
			}
			data[j+1] = pointer;//插在第j个元素后面，因为从第j个元素开始不满足大于条件。
		}
	}
}
//No. 4 堆排序
// 选择排序的改进版
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定
void adjustHeap(int data[], int s, int length) {
	for (int i = 2 * s + 1; i < length; i = 2 * i + 1) {
		if (i < length - 1 && data[i]<data[i + 1]) {//i < length - 1确保i+1存在
			i++;
		}//i是左右节点中较大的值的下标。
		if (data[s] >= data[i])
			break;//没有必要比较更深的节点了。
		else {
			swap(data, s, i);
		}
		s = i;//
	}
}
void heapSort(int data[], int length)//使用大顶堆，每个父节点大于等于左右子节点。
{
	//初始化堆，需要遍历每个非末端节点
	//若父节点为i（从0开始），左节点 2*i+1 右节点2*i+2；范围是0~length/2-1
	for (int i = length / 2 - 1; i >= 0; i--) {
		adjustHeap(data, i, length);
	}
	for (int i = length-1; i >=0; i--) {
		swap(data, 0, i);//末尾元素交换
		adjustHeap(data, 0, i);
	}
}



//No.5 归并排序
// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定
//先拆，再按顺序合并。可使用递归实现与迭代实现。
void Merge(int data[])
{
}
//
void mergeSort(int data[], int length)
{
	for (int i = 2 * s + 1; i < length; i = 2 * i + 1) {
		
    }
}


//No.6 快速排序
// 分类 ------------ 内部比较排序
// 数据结构 --------- 数组
// 每一次划分内部的复杂度是n ，均匀的情况下只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 最差时间复杂度 ---- 每次选取的基准都是最大的元素（或者每次都是最小），导致每次只划分出了一个子序列，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(logn)～O(n),主要是递归造成的栈空间的使用(用来保存left和right等局部变量),取决于递归树的深度
// 一般为O(logn),最差为O(n)（基本有序的情况）
// 稳定性 ---------- 不稳定
int Partition(int data[],int left,int right)
{
	int pivotKey;
	////使用三数取中法,得到pivot
	//int middle = left + (right - left) / 2;
	//if (data[left]>data[right])
	//{
	//	swap(data, left, right);
	//}
	//if (data[middle]>data[right])
	//{
	//	swap(data, middle, right);
	//}
	//if (data[middle]>data[left])
	//{
	//	swap(data, middle, left);//把数据的中值放在left的位置
	//}
	//三值取中法结束，如果不使用该方法，注释掉即可，使用数组left值作为pivot
	pivotKey = data[left];
	while (left < right)
	{
		while (left<right&&data[right]>pivotKey)
		{
			right--;
		}
		swap(data, left, right);
		while (left<right&&data[left]<pivotKey)
		{
			left++;
		}
		swap(data, left, right);
	}
	return left;
}
void QuickSort(int data[],int left,int right)
{
	int pivotIndex;
	if ( left<right )
	{
		pivotIndex = Partition(data, left, right);
		QuickSort(data, left, pivotIndex-1);
		QuickSort(data, pivotIndex + 1, right);
	}
}
void main()
{
	int data[] = { 15,30,10,20,50,80,5,2 };
	/*QuickSort(data, 0, 7);
	InsertSort(data, 8);
	SelectSort(data, 8);
	BubbleSort(data , 8);
	heapSort(data, 8);*/
	mergeSort(data, 8);
	printf("welcome");
}
