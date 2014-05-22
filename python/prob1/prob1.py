#!/usr/bin/python
limit = 1000
itr = 1
ans = 0
while (itr < limit):
	if (itr % 3 == 0) or (itr % 5 == 0):
		ans = ans + itr
	itr = itr + 1
print ans
