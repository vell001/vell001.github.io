package vell.bibi.sort_algorithms;

import vell.bibi.sort_algorithms.util.vell001;

public class MergeSort {
	
	public static void merge(int[] a, int low, int mid, int high){
		int i=low, j=mid, k=0;
		int[] cup = new int[high-low];
		while(i<mid && j<high){
			if(a[i] <= a[j])
				cup[k++] = a[i++];
			else
				cup[k++] = a[j++];
		}
		while(i<mid) cup[k++] = a[i++];
		while(j<high) cup[k++] = a[j++];
		
		for(k=0; k<cup.length; k++){
			a[low + k] = cup[k];
		}
	}
	
	public static void sort(int[] a, int low, int high){
		if(high - low <= 1) return;
		int mid = (high + low) / 2;
		sort(a, low, mid);
		sort(a, mid, high);
		merge(a, low, mid, high);
	}

	public static void main(String[] args) {
		int[] a = vell001.getRandomList(10, 100);
		vell001.printList(a);
		sort(a, 0, a.length);
		vell001.printList(a);
	}

}
