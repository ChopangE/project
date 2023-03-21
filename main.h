#include<stdio.h>

#ifndef __p1__
#define __p1__
int sum_between_two(int a, int b)
{
	int sum = 0;
	int i;
	if ( b < a )
	{
		for (  i = b + 1; i < a; i++ )
		{
			sum += i;
		}
		return sum;
	}
	for ( i = a + 1; i < b; i++ )
	{
		sum += i;
	}
	return sum;
}
int gcd(int a, int b)
{
	if ( b == 0 || a == 0 )
		return 0;
	else
	{
		if ( a > b )
		{
			if ( a % b == 0 )
				return b;
			else
				return gcd(b, a % b);
		}
		else
		{
			if ( b % a == 0 )
				return a;
			else
				return gcd(a, b % a);

		}
	}

}
int lcm(int a, int b)
{
	if ( a == 0 || b == 0 )
		return 0;
	else
	{
		int n_gcd = gcd(a, b);
		if ( a > b )
		{
			return b * a / n_gcd;
		}
		else
		{
			return a * b / n_gcd;
		}
	}

}
#endif
