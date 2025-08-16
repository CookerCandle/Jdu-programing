function cleanText(text) {
    let result = "";
  
    if (text.length >= 1 && text[0] === 'a') {
      result += 'a';
    }
  
    if (text.length >= 2 && text[1] === 'b') {
      result += 'b';
    }
  
    // Добавляем оставшуюся часть строки, начиная с третьего символа (индекс 2)
    result += text.slice(2);
  
    return result;
  }
  

console.log(cleanText('saxiy'));