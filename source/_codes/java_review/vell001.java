package vell.bibi.sort_algorithms.util;

public class vell001 {
	
	public static void printList(int[] a){
		for(int i=0; i<a.length; i++){
			System.out.print(a[i] + "  ");
		}
		System.out.println();
	}
	
	public static int[] getRandomList(int n, int max){
		int[] a = new int[n];
		for(int i=0; i<n; i++){
			a[i] = (int)(Math.random() * max);
		}
		return a;
	}
}
