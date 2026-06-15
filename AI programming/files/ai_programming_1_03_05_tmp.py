# 正負判定→偶数・奇数判定をネストで実装するプログラム

# 整数を入力
number = int(input("整数を入力してください: "))

# 正負の判定（外側のif文）
___BLANK___
    # 偶数・奇数の判定（内側のif文）
    ___BLANK___
        print(f"{number}は正の偶数です。")
    else:
        print(f"{number}は正の奇数です。")
___BLANK___
    if number % 2 == 0:
        print(f"{number}は負の偶数です。")
    ___BLANK___
        print(f"{number}は負の奇数です。")
___BLANK___
    print("0です。")
