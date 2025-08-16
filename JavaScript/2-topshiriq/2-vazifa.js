let uzun = 1
let baland = 1

function counter(uzun, baland) {
    uzun = uzun * 12; // 1 qatorga qancha ketishi 
    baland = baland * 100; // sm ga otqazish
    console.log("gisht ketti:", (baland / 5) * uzun)
}

counter(uzun, baland)