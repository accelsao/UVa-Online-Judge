while 1:
    try:
        n = int(input())
    except EOFError:
        break
    if ((n >= 0 and n <= 7) or (n < 0 and n % 2 == 0)):
        print("Underflow!")
    elif (n == 8):
        print("40320")
    elif (n == 9):
        print("362880")
    elif (n == 10):
        print("3628800")
    elif (n == 11):
        print("39916800")
    elif (n == 12):
        print("479001600")
    elif (n == 13):
        print("6227020800")
    else:
        print("Overflow!")
