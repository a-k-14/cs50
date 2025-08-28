# from cs50 import get_int

# try:
#     n = int(input("Number: "))
# except ValueError:
#     print("Not an Integer!")
# else:
    # print(f"{n=}")

# to ensure we only accept numbers
# an alternate to cs50 get_int implementation
def get_int():
    while True:
        try:
            number = int(input("Number: "))
        except ValueError:
            print("Enter a valid number!")
        else:
            return number
        
# ensure input number > 0
while True:
    number = get_int()
    if number > 0:
        break

# horizontal ? blocks
# print("|", end="")
# for _ in range(number):
#     print("?|", end="")
# print("?|" * number)
# print()

# grid
for _ in range(number):
    print("#" * number)
