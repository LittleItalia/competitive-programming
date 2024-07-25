# Read the matrix from "test.inp" and print it to "test.out"

def read_matrix(file_path):
    """Read a matrix from a file."""
    matrix = []
    try:
        with open(file_path, 'r') as file:
            for line in file:
                row = list(map(int, line.split()))
                matrix.append(row)
    except FileNotFoundError:
        print(f"The file {file_path} does not exist.")
    return matrix

def write_matrix(file_path, matrix):
    """Write a matrix to a file."""
    with open(file_path, 'w') as file:
        for row in matrix:
            file.write(' '.join(map(str, row)) + '\n')

# File paths
input_file = 'test.inp'
output_file = 'test.out'

# Read the matrix from the input file
matrix = read_matrix(input_file)

# Write the matrix to the output file
write_matrix(output_file, matrix)

print(f"Matrix has been read from {input_file} and written to {output_file}.")