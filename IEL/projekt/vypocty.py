from sympy import symbols, Eq, solve, sin
import numpy as np
import matplotlib.pyplot as plt
import math
#prvni priklad
r_1 = 450
r_2 = 810
r_3 = 190
r_4 = 220
r_5 = 220
r_6 = 720
r_7 = 260
r_8 = 180
u_1 = 100
u_2 = 80
u = u_1 + u_2

r_56 = (r_6 * r_5) / (r_6 + r_5)
r_A1 = ((r_2 * r_3) / (r_2 + r_3 + r_4)) + r_1
r_B56 = (r_2 * r_4) / (r_2 + r_3 + r_4) + r_56
r_C7 = (r_3 * r_4) / (r_2 + r_3 + r_4) + r_7
r = ((r_B56 * r_C7) / (r_B56 + r_C7)) + r_A1 + r_8
i = float(u) / r
u_r7 = float(r_7) * i
u_r1 = float(r_1) * i
u_r8 = float(r_8) * i
u_r3 = float(u) - u_r7 - u_r1 - u_r8
I_r3 = u_r3 / r_3
print("Prvni priklad")
print(f"celkovy odpor R: {r:.4f}")
print(f"celkovy proud obvodu I: {i:.4f}")
print(f"napeti na R3 (u_r3): {u_r3:.4f}")
print(f"proud v  R3 (i_r3): {I_r3:.4f}")

#druhy priklad
u_1 = 130
u_2 = 180
r_1 = 350
r_2 = 600
r_3 = 195
r_4 = 650
r_5 = 80
r_34 = (r_3 * r_4) / (r_3 + r_4)
r_12 = r_1 + r_2
r_i = (r_12 * r_5) / (r_12+r_5)
i_x = (u_2 - u_1) / (r_12 + r_5)
u_i = float(u_1) + float(r_12) * i_x
i_r34 = u_i / (r_i + r_34)
u_r34 = i_r34 * r_34
u_r4 = u_r34
i_r4 = u_r34 / r_4
print("Druheho prikladu:")
print(f"napeti v R4 (u_r3): {u_r4:.4f}")
print(f"proud R4 (i_r3): {i_r4:.4f}")

#treti priklad

U_A, U_B, U_C = symbols('U_A U_B U_C')
eq1 = Eq(((130 - U_A) / 47) + ((U_B - U_A) / 28) - ((90 - (U_B - U_A)) / 58) - U_A / 39, 0)
eq2 = Eq((5 / 10) + ((90 - (U_B - U_A)) / 58) - ((U_B-U_A) / 28) - ((U_B - U_C) / 35), 0)
eq3 = Eq(((U_B - U_C) / 35) - (5 / 10) - (U_C / 25), 0)
reseni  = solve((eq1, eq2, eq3), (U_A, U_B, U_C))
print("Treti priklad:")
U_r2 = 0
for var, solution in reseni.items():
    print(f"{var} = {solution.evalf():.4f}")
    if var == U_A:
        U_r2 = solution.evalf()
        print(f"U_r2 = {U_r2:.4f}")
r_2 = 39
I_r3 = U_r2 / r_2
print(f"proud prochazejici R3: {I_r3:.4f}")
#ctvrrty priklad
U1 = 3
U2 = 4
R1 = 10
R2 = 13
L1 = 220e-3
L2 = 70e-3
C1 = 230e-6
C2 = 85e-6
f = 75
omega = 2 * math.pi * f
t = math.pi / (2 * omega)

I1, I2 = symbols("I1 I2")

u1 = U1 * sin(omega * t)
u2 = U2 * sin(omega * t)

Ur1 = I2 * R1 * sin(omega * t)
Ur2 = I1 * R2 * sin(omega * t)

Ul1 = I1 * omega * L1 * sin(omega * t + math.pi / 2)
Ul2 = I2 * omega * L2 * sin(omega * t + math.pi / 2)

Uc1 = I2 / (omega * C1) * sin(omega * t - math.pi / 2)
Uc2 = I1 / (omega * C2) * sin(omega * t - math.pi / 2)

eq1 = Eq(-u1 - u2 + Ur1 + Ul2 + Uc2, 0)
eq2 = Eq(-u1 + Uc1 + Uc2, 0)
eq3 = Eq(-Ul2 - Uc2 + Ur2, 0)

reseni = solve((eq1, eq2, eq3), (I1, I2))

for var,solution in reseni.items():
    print(f"{var} = {solution.evalf():.4f}")
    if var == I1:
        print("napeti na L1 je: ")

#paty priklad graf
def I_L(t):
    return 0.5 + (15/2) * np.exp(-5 * t)
t_values = np.linspace(0,2,1000)
I_L_values = I_L(t_values)
plt.figure(figsize=(10, 6))
plt.plot(t_values, I_L_values, label=r"$I_L = \frac{1}{2} + \frac{15}{2} \times e^{-5t}$")
plt.xlabel("Time (t)")
plt.ylabel("Current $I_L$")
plt.title("Plot of $I_L$ over time")
plt.legend()
plt.savefig("graf5priklad.png", dpi=300)
plt.show()
