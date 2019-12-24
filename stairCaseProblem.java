//Staircase problem Dynamic Approach
//Tanvir Deol
//Output number of ways to climb N stairs if the 
//person can only climb upto 3 stairs at a time
public class stairCaseProblem {

	public static int numberOfWays(int n) {
		//creates new int[] to store previous values
		int[] ways = new int[n+1];
		//initial values are 0,1 and 2 stairs
		ways[0]=1;
		ways[1]=1;
		ways[2]=2;
		//the number of ways to climb i stairs is the the
		//sum of the no. of ways to climb (i-1)+(i-2)+(i-3) stairs
		for (int i =3;i<=n;i++) {
			ways[i]= ways[i-1]+ways[i-2]+ways[i-3];
		}
		
		return ways[n];
	}
	
	
	
	public static void main(String[] args) {
		//Outputs the number of ways it takes to climb 12 stairs
		System.out.print(numberOfWays(12));

	}

}
