def find_largest_number(numbers):
    if not numbers:  # Check if the list is empty
        return None
    return max(numbers)

# Example usage
numbers = [10, 25, 99, 54, 78]
largest = find_largest_number(numbers)
print("The largest number is:", largest)
