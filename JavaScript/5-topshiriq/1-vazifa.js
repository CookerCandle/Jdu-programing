let xazina = [2, 4, 22, 2]

function XazinaTop(xarita) {
    for (let  i = 0; i < xarita.length; i++) {
        if (xarita[i] % 2 != 0) {
            return "xazina topilmadi :("
        }else{
           continue
        }
       
    } return "xazina topildi :)"
}
console.log(XazinaTop(xazina))