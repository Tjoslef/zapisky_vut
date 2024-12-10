from sympy import symbols, Eq, solve, simplify
import numpy as np
import matplotlib.pyplot as plt
import math
import cmath

def format_complex(z):
    real_part = f"{z.real:.4f}" if z.real != 0 else ""
    imag_part = f"{z.imag:.4f}j" if z.imag != 0 else ""
    if real_part and imag_part:
        return f"{real_part} + {imag_part}" if z.imag > 0 else f"{real_part} - {abs(z.imag):.4f}j"
    return real_part or imag_part

# prvni priklad
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
u_ra = r_A1 * i
u_B567C = i * ((r_B56 * r_C7) / (r_B56 + r_C7))
if round(u - u_ra - u_r8) == round(u_B567C):
    print("kontrola ok")
Ic7 = u_B567C / r_C7
u_r7 = Ic7 * r_7
u_r3 = u - u_r7 - u_r1 - u_r8
I_r3 = u_r3 / r_3

print("Prvni priklad")
print(f"r_56 : {r_56:.4f}")
print(f"r_A1 : {r_A1:.4f}")
print(f"r_B56 : {r_B56:.4f}")
print(f"r_C7 : {r_C7:.4f}")
print(f"u_r7 : {u_r7:.4f}")
print(f"u_r8 : {u_r8:.4f}")
print(f"u_r1 : {u_r1:.4f}")
print(f"celkovy odpor R: {r:.4f}")
print(f"celkovy proud obvodu I: {i:.4f}")
print(f"u_B567C : {u_B567C}")
print(f" Ic7 : {Ic7}")
print(f" u_r7 : {u_r7}")
print(f"napeti na R3 (u_r3): {u_r3:.4f}")
print(f"proud v  R3 (i_r3): {I_r3:.4f}")

# druhy priklad
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
print(f" Ri: {r_i:.4f}")
print(f" Ix: {i_x:.4f}")
print(f" U_i: {u_i:.4f}")
print(f" I_r34: {i_r34:.4f}")
print(f"napeti v R4 (u_r3): {u_r4:.4f}")
print(f"proud R4 (i_r3): {i_r4:.4f}")

# treti priklad

U_A, U_B, U_C = symbols('U_A U_B U_C')
eq1 = Eq(((130 - U_A) / 47) + ((U_B - U_A) / 28) - ((90 - (U_B - U_A)) / 58) - U_A / 39, 0)
eq2 = Eq((5 / 10) + ((90 - (U_B - U_A)) / 58) - ((U_B-U_A) / 28) - ((U_B - U_C) / 35), 0)
eq3 = Eq(((U_B - U_C) / 35) - (5 / 10) - (U_C / 25), 0)
simplified_eq1 = simplify(eq1)
simplified_eq2 = simplify(eq2)
simplified_eq3 = simplify(eq3)
print("Simplified Equation 1:", simplified_eq1)
print("Simplified Equation 2:", simplified_eq2)
print("Simplified Equation 3:", simplified_eq3)
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
print("ctvrty priklad")
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
Z_c1 = -1j/(omega * C1)
Z_c2 = -1j/(omega * C2)
Z_l2 = 1j * omega * L2
Z_l1 = 1j * omega * L1
I_a, I_b, I_c = symbols('I_a I_b I_c')
#  |---C1----------|
#  R1      IA      u2
#  |-u1-----L2-----|
#  |       |       |
#  |  IB   C2   IC |
#  |       |       |
#  |---L2-----R2---|
print(f"omega: {omega}")
print(f"t: {t}")
print(f"Z_c1: {format_complex(Z_c1)}")
print(f"Z_c2: {format_complex(Z_c2)}")
print(f"Z_l2: {format_complex(Z_l2)}")
print(f"Z_l1: {format_complex(Z_l1)}")

# Print complex values with real and imaginary parts
eq1 = Eq((Z_c1 + R1) * I_a + Z_l2 * (I_a - I_c) + U1 - U2, 0)
eq2 = Eq(-U1 + I_b * Z_l1 + Z_c2 * (I_b - I_c), 0)
eq3 = Eq(-Z_l2 * (I_a - I_c) - Z_c2 * (I_b - I_c) + I_c * R2, 0)
reseni = solve((eq1, eq2, eq3), (I_a, I_b, I_c))

for var, solution in reseni.items():
    real_num, imag_num = solution.as_real_imag()
    print(f" {var}  {format_complex(complex(solution))}")
I_b = reseni[I_b]
U_L1 = I_b * Z_l1
print(f"U_L1 = {U_L1}")
fazovy_posun_rad = cmath.phase(U_L1)
fazovy_posun_deg = math.degrees(fazovy_posun_rad)
print(f"fazovy_posun v radianech = {fazovy_posun_rad:.4f}")
print(f"fazovy_posun ve stupnich = {fazovy_posun_deg}")
magnitute = abs(U_L1)
real_num_UL1, imag_num_UL1 = U_L1.as_real_imag()
#should be 3.383
print(f"Real part Ul1= {real_num.evalf():.4f}")
print(f"Imaginary part Ul1 = {imag_num.evalf():.4f}")
print(f"magnitute of UL_1 = {magnitute:.4f}")
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
plt.pause(10)
plt.close()
