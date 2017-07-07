package vell.bibi.sort_algorithms;

import vell.bibi.sort_algorithms.util.vell001;

public class ShellSort {
	
	public static void sort(int[] a){
		int i, j, d, cup;
		for(d=a.length/2; d>0; d=d/2){
			for(i=d; i<a.length; i++){
				cup = a[i];
				for(j=i-d; j>=0 && a[j]>cup; j=j-d){
					a[j+d] = a[j];
				}
				a[j+d] = cup;
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
