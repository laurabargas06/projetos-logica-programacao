def main():
    num = int (input())
    x = 1
    codletra = 65
    for i in range(num):
        letra = chr(codletra)
        print(f"{letra}{x}", end=" ")
        x+=2 
        codletra+=2 

main()