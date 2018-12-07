# -*- coding: utf-8 -*-
# project: sort algrithoms
# author: xhj


"""
@ 选择排序算法

  选择排序的原理是不断从未排序的序列中选择最小（最大值），插入
  到第i位
"""
def swap(array, index1, index2):
	assert(index1 != index2)
	array[index1] = array[index1] ^ array[index2]
	array[index2] = array[index1] ^ array[index2]
	array[index1] = array[index1] ^ array[index2]

def select_sort(array):
	""" 
	@ note:
	- 一般的选择排序算法，不断地从待排序列中选择最小（最大）值，
	  与第i位数据交换

	@ param array: 待排序数组
	"""

	num = len(array)
	i = 0
	while i < num - 1:        
		j = i + 1
		min_index = i 
		while j < num:         # 搜索一轮最小值
			if array[j] < array[min_index]:
				min_index = j
			j += 1
		if min_index != i:
			swap(array, min_index, i)
		i += 1

def double_select_sort(array):
	"""
	@ note:
	- 在一般的选择排序中，一次只选择一个最大（最小）值，效率比较低，
	  而在一次选择中，其实可以同时选出最大最小值，分别从两个方向进
	  行更新序列。并且当选择的最大值和最小值相等时，说明已经排好序
	  了，可以直接退出

	@ param array: 待排序数组
	"""

	num = len(array)
	head = 0; tail = num - 1
	while head < tail:
		min_index = head
		max_index = tail
		j = head + 1
		while j < tail:         # 搜索一轮最小值和最大值
			if array[j] < array[min_index]:
				min_index = j
			elif array[j] > array[max_index]:
				max_index = j
			if array[max_index] == array[min_index]:
				# 其实当array[max_index]==array[min_index]时，一定有max_index==min_index
				# 当不存在重复值时，肯定成立，当存在重复值时，上面比较的过程中不包含等号
				# 时，index为第一个重复值的位置，包含等号时，为最后一个重复值的位置
				return
			j += 1


if __name__ == '__main__':
	a = [1, 2, 3, 6, 2, 90, 12, 4, 23]
	select_sort(a)
	print(a)