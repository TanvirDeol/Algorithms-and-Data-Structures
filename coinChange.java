//Coin Change Dynamic Programming Approach
//Tanvir Deol
public class coinChange {

	public static int possibilities(int sum, int[] coins) {
	//create new int[] that stores possibilities for each sum value 
	//from 0->sum, at the end, the number in index of sum is returned
	int[] outcomesPerNum= new int[sum+1];
	//if the total is 0, there is only 1 possibility
	outcomesPerNum[0]= 1;
	//loop through ever type of coin and calculate the number of outcomes 
	//once the coin value is removed from sum
	for (int coin :coins) {
	//loop through every sum value upto 43 
	for (int i =1;i<outcomesPerNum.length;i++) {	
	//if the sum value is less than the coin value, then there is no
	//possibility
		if (i>=coin)
	//incrment the num of possibilities by adding sum-coin value possibilities
	//example sum 7 += sum 2, it adds all the possibilities from 2 to itself. 
	//Since its only one 5cent coin away (1 move)
			outcomesPerNum[i] += outcomesPerNum[i-coin];
		}	
	}
	//lastly return the value in the array, stored in the sum index.
		return outcomesPerNum[sum];
	}
	
	
	
	//Driver Code
	public static void main(String[] args) {
		System.out.print(possibilities(43, new int[]{1,2,5}));

	}

}
