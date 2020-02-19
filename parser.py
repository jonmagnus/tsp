import csv

n = 23
print(n)
filename = './european_cities.csv'
with open(filename, 'r') as infile:
    reader = csv.reader(infile, delimiter=';')
    next(reader, None)  # Skip header
    for i, line  in enumerate(reader):
        if i >= n:
            break 
        for element in line[:n]:
            print(int(float(element)*100))
