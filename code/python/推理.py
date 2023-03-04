w = ["A","B","C","D","E"]
b = "A"
cnt=(b=="D")+(b!="B")+(b!="E")+(b=="D")+(b=="B")
if (cnt == 3):
    print("%s是小偷",b)
else:
    print(b,"不是小偷")
    