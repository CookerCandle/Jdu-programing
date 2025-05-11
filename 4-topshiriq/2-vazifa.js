function tubSon(son) {
    if (son <= 1) return false;

    for (let i = 2; i <= Math.sqrt(son); i++) {
        if (son % i === 0) {
        return false; 
        }
    }

    return true;
}

console.log(tubSon(2));