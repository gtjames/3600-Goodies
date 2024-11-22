import threading
def nprint(n):
    while (n > 0):
        print (n, end="")
        n -= 1
n = int(input("Enter an integer: "))

thread1 = threading.Thread(target=nprint, args=(n,))
thread2 = threading.Thread(target=nprint, args=(n,))

thread1.start()
thread2.start()

thread1.join()
thread2.join()


def example(a):
    a = a + '2'
    a = a * 2 
    return a

x = example("hello") 
print (x)
