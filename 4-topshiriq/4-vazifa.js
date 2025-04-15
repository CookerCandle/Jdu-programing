a = 1
b = 1

function fibonachi(n) {
    for(let i = 1; i <= n; i++){
        console.log(a)
        c = a + b
        a = b 
        b = c
    }
}

fibonachi(8)