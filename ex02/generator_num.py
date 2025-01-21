import random

def generate_random_numbers(count, lower_bound=1, upper_bound=10000):
    """
    Generate a list of random positive numbers.

    Args:
        count (int): Number of random numbers to generate.
        lower_bound (int): Minimum value for the random numbers (default is 1).
        upper_bound (int): Maximum value for the random numbers (default is 10000).

    Returns:
        list: A list of random positive numbers.
    """
    if count <= 0:
        raise ValueError("Count must be a positive integer.")
    if lower_bound <= 0:
        raise ValueError("Lower bound must be a positive integer.")
    return [random.randint(lower_bound, upper_bound) for _ in range(count)]

# Generate 3500 random positive numbers
random_numbers = generate_random_numbers(3500)

# Print numbers separated by a single space
print(" ".join(map(str, random_numbers)))
