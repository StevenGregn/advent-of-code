total_points = 0

with open("input.txt", "r") as file:
    for line in file:
        card = line.strip()
        pipe = card.find('|')

        # Get #'s before pipe
        before_pipe = card[:pipe].split()
        win_nums = set()

        # Extract winning numbers
        for num in before_pipe:
            try:
                win_nums.add(int(num))
            except ValueError:
                continue

        # Get #'s after the pipe
        after_pipe = card[pipe + 1:].split()
        my_nums = set()

        # Extract your numbers
        for num in after_pipe:
            try:
                my_nums.add(int(num))
            except ValueError:
                continue

        # Calculate points
        one = 0
        two_pow = 0

        for n in my_nums:
            if n in win_nums:
                if not one:
                    one = 1
                else:
                    two_pow += 1

        card_total = one * 2**two_pow
        total_points += card_total

print("Total Points:", total_points)
