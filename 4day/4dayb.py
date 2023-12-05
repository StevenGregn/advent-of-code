totalCards = 0
games = {}
cardCounts = {}
gameCount = 0
with open("input.txt", "r") as file:
    for line in file:
        gameCount += 1
        cardCounts[gameCount] = 1
        winNums, cardNums = set(), set()
        card = line.strip()
        pipe = card.find('|')
        
        beforePipe = card[:pipe]
        semi = beforePipe.find(':')
        gameNum = None
        for l in beforePipe[:semi].split():
            if l.isdigit(): gameNum = int(l)
        # extract winning numbers
        for num in beforePipe.split():
            if num.isdigit(): winNums.add(num)
        afterPipe = card[pipe+1:]
        # extract player numbers
        for num in afterPipe.split(): 
            if num.isdigit(): cardNums.add(num)
        games[gameNum] = (winNums, cardNums)
for gameNum, (winNums, cardNums) in games.items():
    winCount = 0
    for num in cardNums: 
        if num in winNums: winCount += 1
    if winCount:
        for win in range(1, winCount + 1):
            cardCounts[gameNum + win] += 1 * max(cardCounts[gameNum], 1)
    # print(gameNum, cardCounts)
print(cardCounts, sum(cardCounts.values()))
    
# print(games)
        
        
        
        