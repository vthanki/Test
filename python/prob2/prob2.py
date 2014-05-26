#!/usr/bin/python

limit=(4*1024*1024)
isum = 0
def fibbo(x):
	lsum = 0
	term = 0
	prev = 0
	curr = 1
	while (term < x):
		term = prev + curr;
	#	print term
		if (term % 2 == 0):
			lsum += term
		prev = curr;
		curr = term;
	return lsum

isum = fibbo(limit)
print isum

