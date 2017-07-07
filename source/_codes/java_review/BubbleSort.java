package vell.bibi.sort_algorithms;

import vell.bibi.sort_algorithms.util.vell001;

public class BubbleSort {

	public static void sort(int[] a){
		int i, j, cup;
		boolean flag;
		for(i=a.length, flag=true; flag && i>0; i--){
			flag = false;
			for(j=0; j<i-1; j++){
				if(a[j] > a[j+1]){
					cup = a[j];
					a[j] = a[j+1];
					a[j+1] = cup;
					flag = true;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		int[] a = vell001.getRandomList(10, 100);
		vell001.printList(a);
		sort(a);
		vell001.printList(a);
	}

}
