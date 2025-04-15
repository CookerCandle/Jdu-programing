function KabisaYili(yil) { 
    if (yil % 4 == 0 && yil % 100 != 0 || yil % 400 == 0) {
        return true;
    } else {
        return false;
    }
}

console.log(KabisaYili(2024))
