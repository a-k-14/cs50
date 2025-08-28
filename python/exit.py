import sys

if len(sys.argv) < 2:
    print("Incorrect command-line arguments.")
    sys.exit(1)
else:
    print(f"Hello, {sys.argv[1]}")
    sys.exit(0)