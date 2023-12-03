import random

def generate_random_numbers(file_name, total_lines, max_number):
    with open(file_name, 'w') as file:
        for _ in range(total_lines):
            number = random.randint(1, max_number)
            file.write(f"{number}\n")

# Specify the file name and parameters
file_name = "random_numbers.txt"
total_lines = 1000000
max_number = 10000000

generate_random_numbers(file_name, total_lines, max_number)

