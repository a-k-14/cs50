import cowsay

# loops in py
# for _ in range(1, 5):
#     # print(f"{i=}")
#     print("For loop in py...")

# convert input into uppercase
# before: str = input("Before:  ")
# print("After:  ", before.upper())
# for c in before:
#     print(c.upper(), end="")
# print()
# print(f"After:  {input("Before: ").upper()}")

# to check how continue works
# while True:
#     try:
#         number = int(input("Enter Number: "))
#         if number < 0:
#             print("Enter a positive number!")
#             continue
#     except ValueError:
#         print("Enter a valid number!")
#     else:
#         print(f"{number= }")
#         break

user_input = input("What should cow say? ")
cowsay.cow(user_input)

