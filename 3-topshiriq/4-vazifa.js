let a, b, c 

a = 10
b = 20
c = 30

function max(a, b, c) {
    if (a == b && a == c){
        return "Ular teng"
    }else if (a == b && a > c) {
        return "a va b eng katta" 
    }else if (a == c && a > b) {
        return "a av c eng katta"
    }else if (b == c && b > a) {
        return "b va c eng katta"
    }else if (a > b && a > c) {
        return "a eng katta"
    }else if (b > a && b > c) {
        return "b eng katta"    
    }else {
        return "c eng katta"
    }
}
console.log(max(a, b, c))