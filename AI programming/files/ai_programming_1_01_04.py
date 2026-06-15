# 数値の計算とtype()で型の確認


def main():
    # 整数
    a = 10
    print(a, type(a))

    # 小数（浮動小数点数）
    b = 3.14
    print(b, type(b))

    # 文字列
    c = "Hello"
    print(c, type(c))

    # 計算結果の型
    d = 10 / 3
    print(d, type(d))

    e = 10 // 3
    print(e, type(e))


if __name__ == "__main__":
    main()
