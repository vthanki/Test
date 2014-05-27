#!/usr/bin/python

ls = range(1,101)

sum1 = 0
sum2 = 0

for x in ls:
	sum1 += x ** 2
	sum2 += x

print (sum2**2 - sum1)
