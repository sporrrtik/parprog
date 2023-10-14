import os
n1 = 1
n2 = 9900
threads = 10
schedule = "static"
time_delta = []
delta = (n2 - n1) // 10

filename = "omp"

os.system(f"make omp_clean")
os.system(f"make omp")
for i in range(10):
    n1 += delta
    os.system(f"./lab3_omp {n1} 10 omp_{threads}_{schedule}")
        
    with open(f"./omp_{threads}_{schedule}_delt.txt", "r") as f:
        times = [int(line.replace("\n", "").split()[1]) for line in f.readlines()]
        time_delta += [[n1, min(times)]]

    with open(f"./omp_{threads}_{schedule}_delt.txt", "w") as f:
        pass
      
with open(f"./omp_{threads}_{schedule}_delt.txt", "w") as f:
    f.write(str(time_delta))
