package vell.bibi.sort_algorithms;

import vell.bibi.sort_algorithms.util.vell001;

public class HeapSort {

	public static void heapAdjust(int[] a, int father, int length){
		int child, cup;
		for(child=father*2+1, cup=a[father]; child<length; father=child, child=father*2+1){
			if(child+1 < length && a[child+1] > a[child])
				child ++;
			if(a[child] > cup){
				a[father] = a[child];
				a[child] = cup;
			} else
				break;
		}
	}
	
	public static void sort(int[] a){
		int cup;
		for(int i=a.length/2; i>=0; i--){
			heapAdjust(a, i, a.length);
		}
		
		for(int i=a.length-1; i>0; i--){
			cup = a[0];
			a[0] = a[i];
			a[i] = cup;
			heapAdjust(a, 0, i);
		}
	}
	
	public static void main(String[] args) {
		int[] a = vell001.getRandomList(10, 100);
		vell001.printList(a);
		sort(a);
		vell001.printList(a);
	}

}
