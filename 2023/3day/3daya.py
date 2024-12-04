arr = []
with open('input.txt', 'r') as file:
    for line in file:
        nRow = []
        for word in line.split():
            for c in word:
                nRow.append(c)
        arr.append(nRow)
rows, cols = len(arr), len(arr[0])
gearNum = 0
for r in range(rows):
    c = 0
    while c in range(cols):
        hasSymbol = False
        tempNum = ""
        if arr[r][c].isdigit():
            numStart = c
            while c in range(cols) and arr[r][c].isdigit():
                tempNum += arr[r][c]
                c += 1
            numEnd = c - 1
            # print(arr[numStart][numEnd])
            if numEnd + 1 in range(cols) and arr[r][numEnd + 1] != '.': hasSymbol = True
            if numStart - 1 in range(cols) and arr[r][numStart - 1] != '.': hasSymbol = True
            
            if r - 1 in range(rows):
                if numStart - 1 in range(cols) and arr[r - 1][numStart - 1] != '.': hasSymbol = True
                for mid in range(numStart, numEnd + 1):
                    if arr[r - 1][mid] != '.': 
                        hasSymbol = True
                        break
                if numEnd + 1 in range(cols) and arr[r - 1][numEnd + 1] != '.': hasSymbol = True   
            
            if r + 1 in range(rows):
                if numStart - 1 in range(cols) and arr[r + 1][numStart - 1] != '.': hasSymbol = True
                for mid in range(numStart, numEnd + 1):
                    if arr[r + 1][mid] != '.': 
                        hasSymbol = True
                        break
                if numEnd + 1 in range(cols) and arr[r + 1][numEnd + 1] != '.': hasSymbol = True 
        else: c += 1
        if hasSymbol: gearNum += int(tempNum)
print(gearNum)
                