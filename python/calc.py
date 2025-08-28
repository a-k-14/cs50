# truncation
x = int(input("x:  "))
y = int(input("y:  "))
div_res = x / y
print(div_res)
# there is issue with precission
print(f"{div_res:.50f}")

# no worry of integer overflow like c where a big number runs into 0 or -ve


