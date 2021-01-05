# assignment: programming assignment 4
# author: Michael Coe
# date: 11/29/2020
# file: cipher.py is a program that encodes and decodes using a Caesar cipher.
# input: Strings
# output: encoded strings

# read text from a file and return text as a string
def readfile():
    read = input('Please enter a file for reading:\n')
    try:
        f1 = open(read, 'r')
    except:
        return
    message = f1.readlines()  # write your code here
    f1.close()
    return message


# write a string (message) to a file
def writefile(message):
    write = input('Please enter a file for writing:\n')
    try:
        f2 = open(write, 'w')
    except:
        print('Not a Valid file')
        return
    f2.write(message)
    f2.close()
    return
    # write your code here


# make a list (tuple) of letters in the English alphabet
def make_alphabet():
    alphabet = ()
    for i in range(26):
        char = i + 65
        alphabet += (chr(char),)
    # print (alphabet)
    return alphabet


# encode text letter by letter using a Caesar cipher
# return a list of encoded symbols
def encode(plaintext):
    plaintext = plaintext.upper()
    shift = 3
    ciphertext = []
    alphabet = make_alphabet()
    length = len(alphabet)
    for char in plaintext:
        found = False
        for i in range(length):
            if char == alphabet[i]:
                letter = alphabet[(i + shift) % length]
                ciphertext.append(letter)
                found = True
                break
        if not found:
            ciphertext.append(char)
    return ciphertext


# decode text letter by letter using a Caesar cipher
# return a list of decoded symbols
# check how the function encode() is implemented
# your implementation of the function decode() can be very similar
# to the implementation of the function encode()
def decode(text):
    shift = -3
    plaintext = []
    alphabet = make_alphabet()
    length = len(alphabet)
    for char in text:
        found = False
        for i in range(length):
            if char == alphabet[i]:
                letter = alphabet[(i + shift) % length]
                plaintext.append(letter)
                found = True
                break
        if not found:
            plaintext.append(char)
    return plaintext


# convert a list into a string
# for example, the list ["A", "B", "C"] to the string "ABC" or
# the list ["H", "O", "W", " ", "A", "R", "E", " ", "Y", "O", "U", "?"] to the string "HOW ARE YOU?"
def to_string(text):
    s = ""
    for i in text:
        s += str(i)
    return s


# main program
while True:
    action = input('''
Would you like to encode or decode the message?
Type E to encode, D to decode, or Q to quit:
''')
    # if the user decides to quit
    if action == 'q' or action == 'Q':
        break
    elif action == 'e' or action == 'E' or action == 'd' or action == 'D':
        # if encoding happens
        if action == 'e' or action == 'E':
            try:
                plain = to_string(readfile())
            except:
                print('Not a Valid file')
                continue
            code = to_string(encode(plain))
            writefile(code)
            print(f'''
Plaintext:
{plain}

Ciphertext:
{code}''')
        else:
            code = to_string(readfile())
            plain = to_string(decode(code))
            writefile(plain)
            print(f'''
Ciphertext:
{code}

Plaintext:
{plain}
''')

    # if an invalid action is entered
    else:
        print('Not a valid action.')
print('\nGoodbye!')
