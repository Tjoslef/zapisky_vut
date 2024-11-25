import numpy as np


def generator(rows, cols):
    bitmap = np.random.randint(2, size=(rows, cols))
    return bitmap


def write_matrix(bitmap, filename="soubor.txt"):
    with open(filename, 'w') as f:
        for row in bitmap:
            f.write(' '.join(map(str, row)) + '\n')


rows, cols = 10000, 10000
random_bitmap = generator(rows, cols)
write_matrix(random_bitmap)
