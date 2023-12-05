import math
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
def getAdjNumber(arr, r, c):
    number = ""
    # get left part of the number
    numStart, numEnd = c, c
    while numStart in range(cols) and arr[r][numStart].isdigit():
        numStart -= 1
    # get right part of the number
    while numEnd in range(cols) and arr[r][numEnd].isdigit():
        numEnd += 1
    numStart += 1
    number = arr[r][numStart:numEnd]
    # print(number)
    return int("".join(number)) if number else None
    
    
for r in range(rows):
    c = 0
    while c in range(cols):
        firstNum, secondNum = None, None
        num1 = num2 = num3 = num4 = num5 = num6 = num7 = num8 = None
        if arr[r][c] == '*':
            tempC = c
            # Check adjacent elements
            for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]:
                nr, nc = r + dr, c + dc
                if nr in range(rows) and nc in range(cols) and arr[nr][nc].isdigit():
                    num = getAdjNumber(arr, nr, nc)
                    if dr == 0 and dc == 1:
                        num1 = num
                    elif dr == 0 and dc == -1:
                        num2 = num
                    elif dr == 1 and dc == 0:
                        num3 = num
                    elif dr == -1 and dc == 0:
                        num4 = num
                    # if above then don't check diagonals
                    elif dr == 1 and dc == 1 and not num3:
                        num5 = num
                    elif dr == 1 and dc == -1 and not num3:
                        num6 = num
                    # if below then don't check diagonals
                    elif dr == -1 and dc == 1 and not num4:
                        num7 = num
                    elif dr == -1 and dc == -1 and not num4:
                        num8 = num 
            # print(num1, num2, num3, num4, num5, num6, num7, num8)
            # if only two values  
            vals = []
            nums = [num1, num2, num3, num4, num5, num6, num7, num8]
            if nums.count(None) == 6:
                for num in nums:
                    if num != None: vals.append(num)
                # print(nums, math.prod(vals))
                gearNum += math.prod(vals)
        c += 1
print(gearNum)
                