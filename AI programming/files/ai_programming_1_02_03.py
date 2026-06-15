# さまざまな計算

# 商と余り
print(17 // 5)
print(17 % 5)

# 硬貨の計算（1350円を500円玉、100円玉、50円玉で表す）
total = 1350
coin_500 = total // 500
remaining = total % 500
coin_100 = remaining // 100
remaining = remaining % 100
coin_50 = remaining // 50
print("500円玉:", coin_500, "枚")
print("100円玉:", coin_100, "枚")
print("50円玉:", coin_50, "枚")

# 複合代入演算子
count = 0
count += 1
print(count)
count += 5
print(count)

# 比較演算子
print(10 == 10)
print(10 != 5)
print(10 > 20)
print(10 <= 10)
