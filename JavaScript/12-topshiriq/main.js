let siz = 0
let comp = 0

// 1 > qogoz
// 2 > qaychi  
// 3 > tosh

function game(el) {
    const start_comp = Math.floor(Math.random()* 3 + 1)
    const start_siz = el.id

    image_sender(start_comp, start_siz)

    if (start_comp == start_siz) {
        console.log("Durrang")
        document.querySelector(".result").innerHTML = "Durrang"
        siz++
        comp++
    }else if (start_comp == 1 && start_siz == 2) {
        console.log("Siz yutdingiz")
        document.querySelector(".result").innerHTML = "Siz yutdingiz"
        siz++
    }else if (start_comp == 1 && start_siz == 3) {
        console.log("Kompyuter yutdi")
        document.querySelector(".result").innerHTML = "Kompyuter yutdi"
        comp++
    }else if (start_comp == 2 && start_siz == 1) {
        console.log("Kompyuter yutdi")
        document.querySelector(".result").innerHTML = "Kompyuter yutdi"
        comp++
    }else if (start_comp == 2 && start_siz == 3) {
        console.log("Siz yutdingiz")
        document.querySelector(".result").innerHTML = "Siz yutdingiz"
        siz++
    }else if (start_comp == 3 && start_siz == 1) {
        console.log("Siz yutdingiz")
        document.querySelector(".result").innerHTML = "Siz yutdingiz"
        siz++
    }else if (start_comp == 3 && start_siz == 2) {
        console.log("Kompyuter yutdi")
        document.querySelector(".result").innerHTML = "Kompyuter yutdi"
        comp++
    }

    document.querySelector(".komp").innerHTML = `Kompyuter <br> ${comp}`
    document.querySelector(".siz").innerHTML = `Kompyuter <br> ${siz}`
}

function image_sender(comp, siz) {
    if (comp == 1) {
        document.querySelector(".komp_img").src = "img/qogoz.png"
    }else if (comp == 2) {
        document.querySelector(".komp_img").src = "img/qaychi.png"
    }else if (comp == 3) {
        document.querySelector(".komp_img").src = "img/tosh.png"
    }

    if (siz == 1) {
        document.querySelector(".siz_img").src = "img/qogoz.png"
    }else if (siz == 2) {
        document.querySelector(".siz_img").src = "img/qaychi.png"
    }else if (siz == 3) {
        document.querySelector(".siz_img").src = "img/tosh.png"
    }
}