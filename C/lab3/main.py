import os
n1 = 1
n2 = 397
delta = (n2 - n1) // 10
filenames = ("lab1-par-1", "lab1-par-2", "lab1-par-4", "lab1-par-10")
comp= "gcc"
os.system(f"make clean")
os.system(f"make gcc-seq")
for filename in filenames:
    now_len = n1
    print(f"NOW {filename}, N = {now_len}=================================\n===========================================================\n===========================================================\n===========================================================\n===========================================================\n===========================================================")
    for i in range(10):
        now_len += delta
        os.system(f"./{filename} {now_len} 10 {comp}-{filename}")
