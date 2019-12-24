//Fibonacci sequence Dynamic Approach
//Tanvir Deol
public class fibonacci {

	public static int fib(int n) {
		//Creates an array to store all values of i->n in the array
		//these are acessed to reduce computation
		int[] store = new int[n+2];
		store[0]= 0;
		store[1]=1;
	
		int i;
		//from 2->n, the ith element is the sum of index of "i-1"
		//and index "i-2". This keeps repeating until n is reached.
		for (i=2;i<=n;i++) {
			store[i]=store[i-1]+store[i-2];
		}
		//the nth value of the array is returned,since its the 
		//final value
		return store[n];
	}
	//**Driver code**//
	public static void main(String[] args) {
		System.out.print(fib(12));

	}

}
