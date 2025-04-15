function generator(start, stop, step) {
    result = 0
    if (start < stop) {
        for (start; start <= stop; start += step) {
            result += start
        }
    }
    return result
}

console.log(generator(1, 10, 4))
