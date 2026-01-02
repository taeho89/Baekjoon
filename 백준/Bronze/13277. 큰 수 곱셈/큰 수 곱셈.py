import sys

sys.set_int_max_str_digits(1000000)

def solve():
    line = sys.stdin.readline()
    if not line:
        return
    a, b = map(int, line.split())
    
    print(a * b)
    
if __name__ == "__main__":
    solve()