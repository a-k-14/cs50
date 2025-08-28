# scores = [72, 73, 33]
# average = sum(scores) / len(scores)
# print(f"{average=}")

scores = []

for i in range(3):
    score = int(input("Score: "))
    # scores.append(score)
    # scores = scores + [score]
    scores += [score]

average = sum(scores) / len(scores)
print(f"{average=}")
