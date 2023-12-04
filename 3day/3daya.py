arr = []
with open('input.txt', 'r') as file:
    for line in file:
        nRow = []
        for word in line.split():
            for c in word:
                nRow.append(c)
        arr.append(nRow)
rows, cols = len(arr), len(arr[0])
for r in rows:
    for c in cols:
         
print(arr)
                