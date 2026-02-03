import sys
import math

def sub(a, b):
    return (a[0] - b[0], a[1] - b[1])

def cross(a, b):
    return a[0] * b[1] - a[1] * b[0]

def dot(a, b):
    return a[0] * b[0] + a[1] * b[1]

def check(start, dir_vec, base, target):
    num = cross(sub(target, start), dir_vec)
    den = cross(base, dir_vec)
    if den == 0:
        return False
    return num % den == 0

def parse_frac(s):
    if '/' in s:
        parts = s.split('/')
        return int(parts[0]), int(parts[1])
    return int(s), 1

def main():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    
    t = int(input_data[0])
    idx = 1
    
    for _ in range(t):
        if idx + 7 >= len(input_data):
            break
            
        xa, ya, xb, yb, xc, yc = map(int, input_data[idx:idx+6])
        idx += 6
        
        xd_str = input_data[idx]
        yd_str = input_data[idx+1]
        idx += 2
        
        xd1, xd2 = parse_frac(xd_str)
        yd1, yd2 = parse_frac(yd_str)
        
        L = xd2 * yd2
        a = (xa * L, ya * L)
        b = (xb * L, yb * L)
        c = (xc * L, yc * L)
        d = (xd1 * yd2, yd1 * xd2)

        ab = sub(b, a)
        ac = sub(c, a)
        bc = sub(c, b)
        ad = sub(d, a)
        bd = sub(d, b)

        hc = cross(ab, ac)
        hd = cross(ab, ad)

        if hd == 0 or hd == hc:
            print("Yes")
            continue
        
        if not ((hc > 0 and 0 <= hd <= hc) or (hc < 0 and hc <= hd <= 0)):
            print("No")
            continue

        if hd == 0 or hd == hc or check(a, ac, ab, d) or check(b, bc, ab, d):
            print("Yes")
        elif dot(ab, ac) == 0:
            da = dot(ac, ac)
            db = dot(bc, ac)
            dir_vec = (2 * db * ac[0] - da * bc[0], 2 * db * ac[1] - da * bc[1])
            if check(c, dir_vec, ab, d):
                print("Yes")
            else:
                print("No")
        elif dot(ab, bc) == 0:
            db = dot(bc, bc)
            da = dot(ac, bc)
            dir_vec = (2 * da * bc[0] - db * ac[0], 2 * da * bc[1] - db * ac[1])
            if check(c, dir_vec, ab, d):
                print("Yes")
            else:
                print("No")
        else:
            print("No")

if __name__ == "__main__":
    main()