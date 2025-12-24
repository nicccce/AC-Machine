import numpy as np

def f(x):
    return -2*x**3 + 21*x**2 - 60*x + 50

# 参数设置
a = 0.5
b = 3.5
epsilon = 0.8
phi = 0.618  # 黄金比例 ≈ 0.618
k = 0  # 迭代次数

print("使用 0.618 法求解最小值")
print("目标函数: f(x) = -2x³ + 21x² - 60x + 50")
print("初始区间: [", a, ",", b, "]")
print("精度要求: ε =", epsilon)
print("-" * 60)

while b - a > epsilon:
    k += 1
    # 计算两个试探点
    x1 = a + (1 - phi) * (b - a)
    x2 = a + phi * (b - a)
    
    f1 = f(x1)
    f2 = f(x2)
    
    print(f"第 {k} 步:")
    print(f"  区间: [{a:.4f}, {b:.4f}]")
    print(f"  x1 = {x1:.4f}, f(x1) = {f1:.4f}")
    print(f"  x2 = {x2:.4f}, f(x2) = {f2:.4f}")
    
    if f1 < f2:
        # 舍去右半部分
        b = x2
        print(f"  f(x1) < f(x2)，舍去右侧，新区间: [{a:.4f}, {b:.4f}]")
    else:
        # 舍去左半部分
        a = x1
        print(f"  f(x1) >= f(x2)，舍去左侧，新区间: [{a:.4f}, {b:.4f}]")
    
    print()

# 输出最终结果
x_opt = (a + b) / 2
f_opt = f(x_opt)

print("=" * 60)
print("迭代结束！")
print(f"最终区间: [{a:.4f}, {b:.4f}]")
print(f"近似最优解: x* ≈ {x_opt:.4f}")
print(f"最小值: f(x*) ≈ {f_opt:.4f}")