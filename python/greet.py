from sys import argv

# if user typed name along with file name, greet using name
# default len of argv is 1 which is the file name
if len(argv) == 2:
    print(f"Hello, {argv[1]}")
else:
    print("Hello!")