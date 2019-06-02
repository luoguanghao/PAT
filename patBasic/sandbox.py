

a = list(map(int, input().split()))[1:]
A1, A2 = list(filter(lambda c: c % 5 == 0 and c % 2 == 0, a)), list(filter(lambda c: c % 5 == 1, a))
a1 = sum(A1) if A1 else "N"
a2 = sum(map(lambda c: A2[c], range(0, len(A2), 2))) - sum(map(lambda c: A2[c], range(1, len(A2), 2))) if A2 else "N"
a3 = len(list((filter(lambda c: c % 5 == 2, a))))
A4 = list(filter(lambda c: c % 5 == 3, a))
a4 = "{0:.1f}".format(sum(A4) / len(A4)) if A4 else "N"
A5 = list(filter(lambda c: c % 5 == 4, a))
a5 = max(A5) if A5 else "N"
print(a1, a2, a3, a4, a5)
print(A4)