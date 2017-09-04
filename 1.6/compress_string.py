
def compressedString(original_str):
    compressed_string = ''
    i = 0
    # Go through the characters of the original string
    while i < len(original_str):
        c = original_str[i]
        # Add the character we are looking at to the compressed string
        compressed_string = compressed_string + c
        c_count = 0
        # Count the same, contiguous characters in the string
        for j in range(i, len(original_str)):
            if c == original_str[j]:
                c_count = c_count + 1
            else:
                break
        # Add the count of the same, contiguous characters to the compressed string
        if c_count > 1:
            compressed_string = compressed_string + str(c_count)
            # Skip to the next, different character in the string
            i = i + c_count - 1
        i = i + 1

    # Return the compressed string if it is smaller than the original string
    # otherwise return the original string
    if len(compressed_string) < len(original_str):
        return compressed_string
    else:
        return original_str

def assertionTest(test, msg):
    if test:
        print 'PASSED: ', msg
    else:
        print 'FAILED: ', msg

def main():
    str = 'abb'
    assertionTest(compressedString(str) == 'abb', 'Compressed string was not smaller than original string')

    str = 'aabcccccaaa'
    assertionTest(compressedString(str) == 'a2bc5a3', 'String was compressed correctly.')

if __name__ == '__main__':
    main();
