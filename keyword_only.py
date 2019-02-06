def total(initial, *numbers, vegetables):
	count = initial
	for number in numbers:
		count += number
		
	count += vegetables
	
	return count
	
print(total(10, 1, 2, 3, vegetables=50))
print(total(10, 1, 2, 3, ))