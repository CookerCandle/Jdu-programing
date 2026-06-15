# 点数からA/B/C/Dの成績を判定するプログラム

# 点数を入力
score = int(input("点数を入力してください: "))

# 成績判定
if score >= 90:
    grade = "A"
elif score >= 70:
    grade = "B"
elif score >= 50:
    grade = "C"
else:
    grade = "D"

print(f"成績は{grade}です。")
