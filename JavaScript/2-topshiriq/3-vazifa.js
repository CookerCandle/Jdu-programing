let son = 123
let ans = 0
function reverse(son) {
    
    while (son > 0 ) {
        ans = (ans + (son % 10)) * 10
        son = (son - son % 10) / 10
    }
    console.log(ans / 10)
}

reverse(son)