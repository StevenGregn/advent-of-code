i, validNums, colorAmount = 0, 0, -1
d = {'blue,' : 'blue', 'blue' : 'blue', 'blue;': 'blue', 'red,' : 'red', 'red':'red', 'red;' : 'red', 'green' :'green', 'green,':'green', 'green;' : 'green'}
color = ""
validAmounts = {'green':13,'blue':14,'red':12}
with open('input.txt', 'r') as file:
    for line in file:
        #minVals = {'blue':float("inf"),'green':float('inf'),'red':float('inf')}
        addLine = True
        i += 1
        words = line.split()
        for j in range(0, len(words) - 1, 2):
            pair = (words[j], words[j + 1])
            if pair[0].isdigit():
                # print("Pair", pair)
                # print("Val ", pair[0], "Color Val ", validAmounts[d[pair[1]]])
                #minVals[pair[1]] = min(pair[0], minVals[pair[1]])
                if int(pair[0]) > validAmounts[d[pair[1]]]: 
                    addLine = False
                    break
        if addLine: validNums += i
print(validNums)
                
