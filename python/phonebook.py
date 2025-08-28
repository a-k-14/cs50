import csv
import os

name = input("Enter Name: ")
number = input("Enter Phone Number: ")

file_name = "phonebook.csv"
is_file_empty = os.path.exists(file_name) and os.path.getsize(file_name) > 0

with open(file_name, mode="a", newline="") as file:
    writer = csv.DictWriter(file, fieldnames=["Name", "Number"])
    if not is_file_empty:
        writer.writeheader()
    writer.writerow({"Name": name, "Number": number})