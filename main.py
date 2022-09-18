#Libraries --------------------------------------

#import numpy
import time
import multiprocessing as mp

#Functions ---------------------------------------

def isPrime(arr):
    num = 0
    for i in arr:
        num = num * 10 + i

    for i in range(2, num):
        if num % 2 == 0:
            return 0

    return 1

def isPalindrome(arr):
    for i in range(4):
        if not arr[0 + i] == arr[8 - i]:
            return 0
    return 1


def printProc (value):
    cur = mp.current_process()
    return cur._identity


#Main code ----------------------------------------

time_start = time.time()

file = open('text.txt', 'r')
arr = []

for i in range(9):
    arr.append(int(file.read(1)))

pool = mp.Pool(mp.cpu_count())
parameters = [(x) for x in range(4)]
print(pool.map(printProc, parameters))
pool.close()

# while True:

#     if isPalindrome(arr):
#         if isPrime(arr):
#             string = "".join(str(arr))
#             print("\nPrime Palindrome found!\n", string)
#             print("\nTime: %f seconds" %(time.time() - time_start))
#             break
    
#     arr.pop(0)
#     arr.append(int(file.read(1)))



    # for i in range(100)
    #     if tid == 0
    #         [i:i+9] 0 - 9 | 1 - 10
    #     if tid == 1
    #         [i+9:i+18] 9 - 18
    #     if tid == 2
    #         [i+18:i+27] 18 - 27
    #     if tid == 3
    #         [i+27:i+36] 27 - 36 




