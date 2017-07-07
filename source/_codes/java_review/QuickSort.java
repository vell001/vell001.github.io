package vell.bibi.sort_algorithms;

import vell.bibi.sort_algorithms.util.vell001;

public class QuickSort {

	public static int partition(int[] a, int low, int high){
		int cup;
		cup = a[low]; // 保存关键字
		while(high > low){
			while(high > low && a[high] >= cup) high--; // 由high开始找，找到小于关键字的位置 
			a[low] = a[high];
			while(high > low && a[low] <= cup) low ++; // 由low开始找，找到大于关键字的位置
			a[high] = a[low];
		}
		a[low] = cup;
		return low;
	}
	
	public static void sort(int[] a, int low, int high){
		if(high <= low) return;
		int mid = partition(a, low, high); // 分成两个区
		sort(a, low, mid-1);
		sort(a, mid+1, high);
	}
	
	public static void main(String[] args) {
		int[] a = vell001.getRandomList(10, 100);
		vell001.printList(a);
		sort(a, 0, a.length-1);
		vell001.printList(a);
	}
}
