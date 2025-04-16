const secretNumber = Math.floor(Math.random() * 100) + 1;
let guess = null;

while (guess !== secretNumber) {
  guess = parseInt(prompt("1 dan 100 gacha bo'lgan sonni kiriting:"));

  if (isNaN(guess) || guess < 1 || guess > 100) {
    alert("Iltimos, 1 dan 100 gacha bo'lgan to'g'ri son kiriting.");
    continue;
  }

  if (guess < secretNumber) {
    alert("O'ylangan son bundan katta.");
  } else if (guess > secretNumber) {
    alert("O'ylangan son bundan kichik.");
  } else {
    alert("Tabriklaymiz! Siz o'ylangan sonni topdingiz! 🎉");
  }
}
