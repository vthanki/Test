#!/usr/bin/python

def show_factors(x):
	itr = 2;
	while (x != 1):
		if (x % itr == 0):
			x = x / itr;
			print itr
			continue
		else:
			itr = itr + 1;

show_factors(600851475143)
