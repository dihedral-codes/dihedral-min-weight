f = open("generators.txt")
gens = list(map(str.strip, list(f)))
f.close()

f = open("964816.txt")
ninety = list(map(str.strip, list(f)))
f.close

for i in ninety:
	if i in gens:
		print(i)