def main():
	print_oper(10)

def print_oper(number):
	for i in range(number):
		print (f"para {i}, valor de {(i + 1) % 5} ")


main()