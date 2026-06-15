# 偶数・奇数を判定して表示するプログラム

# 整数を入力
number = int(input("整数を入力してください: "))

# 偶数・奇数を判定
if number % 2 == 0:
    print(f"{number}は偶数です。")
else:
    print(f"{number}は奇数です。")
