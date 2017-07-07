package vell.bibi.algorithms.search;

public class BinarySearch {
	
	// 非递归实现
	public static int search(int[] a, int key){
		int low=0, high=a.length-1, mid = 0;
		while(high>=low){
			mid = (high + low) / 2;
			if(key == a[mid]) return mid;
			else if(key > a[mid]) low = mid + 1;
			else high = mid - 1;
		}
		return -1;
	}
	
	// 递归实现
	public static int search(int[] a, int low, int high, int key){
		if(high < low) return -1;
		int mid = (low + high) / 2;
		if(key == a[mid]) return mid;
		else if(key > a[mid]) return search(a, mid+1, high, key);
		else return search(a, low, mid-1, key);
	}
	
	public static void main(String[] args) {
		int[] a = {2,3,4,5,6,7,8,9,10,11};
		System.out.println(search(a, 5));
		System.out.println(search(a, 0, a.length-1, 5));
	}
}
