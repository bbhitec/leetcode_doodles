/*
 * project euler question
 */

package pe001_35mult;

import java.io.Console;

public class Pe001_35mult {

	public static void main(String[] args) {
		int i;
		int sum = 0;
		for (i = 0; i< 1000; i++)
		{
			if ((0 == i % 3) || (0 == i%5)){
				sum += i;
			}

		}
		System.out.println("Multiples of 3 and 5, Problem 1, sum = " + sum);

	}

}
