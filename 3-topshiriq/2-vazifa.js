let son = 132

if (son > 999 || son < 99) {
    console.log("Son 3 xonali emas")
}else if (son % 10 != Math.floor(son / 10 % 10) && son % 10 != Math.floor(son / 100 % 10) && Math.floor(son / 10 % 10) != Math.floor(son / 100 % 10)){
    console.log("sonlar farqlanadi")
}else{
    console.log("bir xil sonlilar bor")
}



let a, b, c

a = son % 10
b = Math.floor(son / 10 % 10)
c = Math.floor(son / 100 % 10)

if (son > 999 || son < 99) {
    console.log("Son 3 xonali emas")
}else if (a != b && a != c && b != c){
    console.log("sonlar farqlanadi")
}else{
    console.log("bir xil sonlilar bor")
}