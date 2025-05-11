const songs = [
    {
        title: 'Ты и Я',
        artist: 'Xcho',
        album: 'none',
        time: '#time',
        image: 'img/Xcho.jpg',
        file: 'musics/song1.mp3',
        lyrics: '1'
    },
    {
        title: 'Комета',
        artist: 'Jony',
        album: 'Комета',
        time: '#time',
        image: 'img/jony.jpg',
        file: 'musics/song2.mp3',
        lyrics: '2'
    },
    {
        title: 'Снова я напиваюсь',
        artist: 'Slawa Marlow',
        album: 'none',
        time: '#time',
        image: 'img/slawa1.jpg',
        file: 'musics/song3.mp3',
        lyrics: '3'
    },
    {
        title: 'Pigstep',
        artist: 'Lena Raine',
        album: 'Minecraft',
        time: '#time',
        image: 'img/pigstep.jpg',
        file: 'musics/song4.mp3',
        lyrics: '4'
    },
    {
        title: 'Suzume',
        artist: 'Suzume no Tojimari',
        album: 'anime',
        time: '#time',
        image: 'img/suzume.jpg',
        file: 'musics/song5.mp3',
        lyrics: '5'
    },
    {
        title: 'Freaks',
        artist: 'Surfe Curse',
        album: '2021',
        time: '#time',
        image: 'img/freaks.jpg',
        file: 'musics/song6.mp3',
        lyrics: '6'
    },
    {
        title: 'Pastlives',
        artist: 'spientdream',
        album: 'Lyrics',
        time: '#time',
        image: 'img/pastlives.jpg',
        file: 'musics/song7.mp3',
        lyrics: '7'
    },
    {
        title: 'Я приду когда зацветет весна',
        artist: 'Алена Швец',
        album: 'Первое свидание',
        time: '#time',
        image: 'img/alena.jpg',
        file: 'musics/song8.mp3',
        lyrics: '8'
    },
    {
        title: 'Дуло',
        artist: 'Morgenshtern',
        album: 'War Thunder',
        time: '#time',
        image: 'img/dulo.jpg',
        file: 'musics/song9.mp3',
        lyrics: '9'
    },
    {
        title: 'Я волна',
        artist: 'DJ SMASH',
        album: 'Fast food',
        time: '#time',
        image: 'img/DJsmash.jpg',
        file: 'musics/song10.mp3',
        lyrics: '10',
    }
];
const text = [
    {
        "id": 1,
        "text": "[Интро]\nА-а-а-а-а\nТолько ты и я (Только ты и я)\n\n[Куплет 1]\nЯ был прав, но не счастлив, разбуди меня огнем\nМожет встать, попытаться, можешь поделиться сном\nEvery day перетяги — дышу музыкой назло\nЯ тону в этой саге, пока дымится нутро\nБере-береги мою любовь\nВпере-впереди моя душа\nЯ не перестал любить без слов\nХочу любоваться, не спеша\nТолько ты и я (Ты и я), позабыли всех других\nТолько ты и я (Ты и я), скоро подарю круги\n\n[Припев]\nВедь нас можно было вернуть\nПока не погасли звёзды (Звёзды)\nИ я только познал ту суть\nЧто для тебя мир мой создан (Создан)\nВедь нас можно было вернуть\nПока не погасли звёзды (Звёзды)\nИ я только познал ту суть\nЧто для тебя мир мой создан (Создан)\n\n[Куплет 2]\nТы как вискарь, я глушу тебя до дна\nВ моих объятьях одна\nДай мне огня, дай мне, дай мне, дай мне\nДай мне влюбится в тебя\nЭто мир не покорежен, пока в её глаза свет\nС тобой буду осторожен, я отбросил этот бред\nИ весною с тобою мы встретимся опять\nНе спорю закрою все дни, что виноват\nПодержу тебя за руку, чтобы не улетела\nЯ был честен, детка, знаешь меня, ты все видела\n\n[Припев]\nВедь нас можно было вернуть\nПока не погасли звёзды (Звёзды)\nИ я только познал ту суть\nЧто для тебя мир мой создан (Создан)\nВедь нас можно было вернуть\nПока не погасли звёзды (Звёзды)\nИ я только познал ту суть\nЧто для тебя мир мой создан (Создан, а-а-а)\n\n[Аутро]\nА-а-а"
    },
    {
        "id": 2,
        "text": "Все без тебя не так\nЛечу к тебе я, словно комета\nИ даже под дулом пистолета\nЯ найду тебя я, я найду тебя я\nВедь без тебя дико мне так\nТы просто подойди ко мне да\nЯ знаю, будет наше это лето\nВедь ты моя да, ведь ты моя да\nВсе, без тебя не так\nЛечу к тебе я словно комета\nИ даже под дулом пистолета\nЯ найду тебя я, я найду тебя я\nБуря мглою небо кроет\nВихри снежные крутя\nТо как зверь она завоет\nТо заплачет, как дитя\nИ если ты найдешь во мне Инь Янь\nОстанови это мучение\nВ тот миг, когда я потерял тебя\nТам вдали падала луна\nВсе без тебя не так\nЛечу к тебе я словно комета\nИ даже под дулом пистолета\nЯ найду тебя я, я найду тебя я\nВедь без тебя дико мне так\nТы просто подойди ко мне да\nЯ знаю, будет наше это лето\nВедь ты моя да, ведь ты моя да\nВсе, без тебя не так\nЛечу к тебе я словно комета\nИ даже под дулом пистолета\nЯ найду тебя я, я найду тебя я"
    },
    {
        "id": 3,
        "text": "А ты считаешь деньги в моём кошельке\nИ ты любишь только деньги, меня не совсем\nИ я вижу, как ты смотришь на этих людей\nУ кого есть своя яхта, тачка, бассейн\nА я? Что я? Что я?\nСнова я напиваюсь, снова говорю \"пока\" (у-у-у-у)\nМы несовместимы, у меня пустой карман\nСнова я напиваюсь, снова говорю \"пока\"\nМы с тобой не будем никогда, никогда, никогда\nСлушай, я дам всё, что захочешь\nСлушай, и, может, даже больше\nСуммы, проси любые суммы\nЛюбишь, надеюсь, меня любишь\nЙа, йа, а-а (а-а), я давно всё понял (ага)\nНе нужен я, нужны деньги, тачки, пойло\nБудут деньки, обещаю, ты вернёшься\nИ я влюблюсь, я влюблюсь в тебя по новой\nСнова я напиваюсь, снова говорю \"пока\" (у-у-у-у)\nМы несовместимы, у меня пустой карман\nСнова я напиваюсь, снова говорю \"пока\"\nМы с тобой не будем никогда, никогда, никогда (у-у-у-у)\nНикогда, никогда (у-у-у-у)\nНикогда, никогда, никогда"

    },
    {
        "id": 4,
        "text": "{Text None}"
    },
    {
        "id": 5,
        "text": "君の中にある 赤と青き線\nそれらが結ばれるのは 心の臓\n風の中でも負けないような声で\n届ける言葉を今は育ててる\n時はまくらぎ 風はにきはだ\n星はうぶすな 人はかげろう\nなんで泣いてるのと聞かれ 答えれる涙なんかじゃ\n僕ら出逢えたことの意味にはまるで追いつかない\nこの身ひとつじゃ 足りない叫び\n君の手に触れた時にだけ震えた心があったよ\n意味をいくつ越えれば僕らは辿りつけるのかな\n愚かさでいい 醜さでいい\n正しさのその先で 君と手を取りたい\n思い出せない 大切な記憶\n言葉にならない ここにある想い\nもしかしたら もしかしたら\nそれだけでこの心はできてる\nもしかしたら もしかしたら\n君に「気づいて」と今もその胸を\n打ち鳴らす\nなんで泣いてるのと聞かれ 答えれる涙なんかじゃ\n僕ら出逢えたことの意味にはまるで追いつかない\nこの身ひとつじゃ 足りない叫び\n君の手に触れた時にだけ震えた心があったよ\n意味をいくつ越えれば僕らは辿りつけるのかな\n愚かさでいい 醜さでいい\n正しさのその先で 君と生きてきたい"
    },
    {
        "id": 6,
        "text": "{Text None}"
    },
    {
        "id": 7,
        "text": "Oh, whoo, ooh-ooh-ooh\nOh, oh, oh-oh-oh\nOh, oh, oh-oh-oh\nPast lives couldn't ever hold me down\nLost love is sweeter when it's finally found\nI've got the strangest feeling\nThis isn't our first time around\nPast lives couldn't ever come between us\nSometimes the dreamers finally wake up\nDon't wake me I'm not dreaming\nDon't wake me I'm not dreaming\nAll my past lives, they got nothing on me\nGolden eagle, you're the one and only, flying high\nThrough the cities in the sky (ooh-ooh)\nI'll take you way back, countless centuries\nDon't you remember that you were meant to be\nMy Queen of Hearts? Meant to be my love?\nThrough all of my lives\nI never thought I'd wait so long for you\nThe timing is right, the stars are aligned\nSo save that heart for me\n'Cause, girl, you know that you're my destiny (d-destiny)\nSwear to the moon, the stars, the sons, and the daughters\nOur love is deeper than the oceans of water\nI need you now, I've waited, oh, so long, yeah\n(Baby love) I need you now, I've waited, oh, so long\nPassing seasons, empty bottles of wine\nMy ancient kingdom came crashing down without you\nBaby child\nI'm lost without your love (ooh-ooh)\nOh, diamond sparrow, my moonlit majesty\nYou know I need you, come flying back to me\nThrough all of my lives\nI never thought I'd wait so long for you\nThe timing is right, the stars are aligned\nSo save that heart for me\n'Cause, girl, you know that you're my destiny (d-destiny)\nSwear to the moon, the stars, the sons, and the daughters\nOur love is deeper than the oceans of water\nSave that heart for me\nAnd, girl, I'll give you everything you need (everything you need)\nHere's to our past lives, our mothers and fathers\nOur love is deeper than the oceans of water\nI need you now, I've waited, oh, so long, yeah\n(Baby love) I need you now, I've waited, oh, so long\n(Hurry) I need you now, I've waited, oh, so long, yeah\n(Baby love) I need you now, I've waited, oh, so long\nSo save that heart for me\n'Cause, girl, you know that you're my destiny (d-destiny)\nSwear to the moon, the stars, the sons, and the daughters\nOur love is deeper than the oceans of water\nSave that heart for me\nAnd, girl, I'll give you everything you need (everything you need)\nHere's to our past lives, our mothers and fathers\nOur love is deeper than the oceans of water\nI need you now, I've waited, oh, so long"
    },
    {
        "id": 8,
        "text": "[Интро]\nЯ приду, когда зацветёт весна\nИ покрасит в розовый собой облака\nСоберу букет полевых цветов\nИ спрячу\nИ моё сердечко болит от любви\nПросто слушай, ничего мне не говори\nПервое свидание последней весны\nЯ плачу\n\n[Припев]\nЯ приду, когда зацветёт весна\nИ покрасит в розовый собой облака\nСоберу букет полевых цветов\nИ спрячу\nИ моё сердечко болит от любви\nПросто слушай, ничего мне не говори\nПервое свидание последней весны\nЯ плачу\n\n[Куплет 1]\nВ городе вчера зацвела сирень\nСыпет лепестки и бросает тень\nСловно в аниме, заблестят зрачки\nНе взаимно, ты прости\nВ питерской квартире кто-то точит ножи\nБудущая жертва собирает цветы\nВстреча их случится, только ты подожди\nПодожди"
    },
    {
        "id": 9,
        "text": "Ай\nРядовой MORGENSHTERN тут, сука\n(Слава, что ты сделал?) Ай, готовьте пушки, ей, ей, е\nЕй, ей, ей, ей\nPull up in the tank, и я еду в бой (ей, ей)\nТут я капитан, боевой ковбой (ей, ей)\nКупил новый ТУ — это самолёт (ей)\n\"Вру-ту-ту-ту-ту-ту-ту\" — это вертолёт (ей, ей)\nPull up in the tank, и я еду в бой (ей, ей)\nТут я капитан, боевой ковбой (ей, ей)\nКупил новый ТУ — это самолёт (ей)\n\"Бэ-э\" — а это ты подох\nА, закрутил на поле боя, будто вертик (а)\nСука ловит пулевое на моей торпеде (на)\nА, тупое мясо посажу на вертель (шаверма)\nА, я впереди, а ты вперде (ха)\nНахуй Lambo, ей, прыгну в самолёт (у-э)\nЭй, тупо лох (лох), пососи дуло (соси)\nНахуй Lambo (фо), прыгну в самолёт (phew)\nЭй, тупо лох (лох), пососи дуло (соси)\nЗаходите, люди, поиграть в War Thunder\nТут, бля, очень красиво\nАлишерка стал дохуя богаче\nWar Thunder, большое спасибо\nТанки, самолёты, вертолёт и корабль\nТут всё есть, чё тебе надо\nПоскорей беги по ссылке в описании — качай War Thunder прямо сейчас\nА я приму ванну из бабок (ей, ей, ей, ей)\nPull up in the tank, и я еду в бой (ей, ей)\nТут я капитан, боевой ковбой (ей, ей)\nКупил новый ТУ — это самолёт (ей)\n\"Вру-ту-ту-ту-ту-ту-ту\" — это вертолёт (ей, ей)\nPull up in the tank, и я еду в бой (ей, ей)\nТут я капитан, боевой ковбой (ей, ей)\nКупил новый ТУ — это самолёт (ей)\n\"Бэ-э\" — а это ты подох"
    },
    {
        "id": 10,
        "text": "{Text None}"
    }
]

const now = new Date();
const xafta = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday'];
const oy = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];

function updateClock() {
    const time = document.getElementById('time');
    const date = document.getElementById('date');

    time.innerHTML = now.toLocaleTimeString([], { hour: '2-digit', minute: '2-digit' });
    date.innerHTML = `${xafta[now.getDay()]}, ${now.getDate()} ${oy[now.getMonth()]}  `;
}
setInterval(updateClock, 1000);

let curSong = 0

const artist = document.getElementById("music-info")
const album = document.getElementById("album")
const back_img = document.getElementsByTagName("main")[0]

const audio = document.getElementById('audio');
const play = document.getElementById('play');
const timeline = document.getElementById('timeline');
const prev = document.getElementById('prev');
const next = document.getElementById('next');
const durationDisplay = document.getElementById('duration');
const music_text = document.getElementsByClassName('music-text')[0];   

audio.setAttribute('src', songs[curSong].file);

audio.addEventListener("loadedmetadata", () => {
    artist.innerHTML = `${songs[curSong].artist} - ${songs[curSong].title}`;
    album.innerHTML = `Album: ${songs[curSong].album}`;

    const container = document.getElementsByClassName("music-albom")[0];

    // Удаляем старый img, если он есть
    const oldImg = container.querySelector("#album-img");
    if (oldImg) {
        oldImg.remove();
    }

    // Добавляем новое изображение
    const albumImg = Object.assign(document.createElement("img"), {
        src: songs[curSong].image,
        id: "album-img",
    });
    container.appendChild(albumImg);

    back_img.style = `background-image: url(${songs[curSong].image})`;

    timeline.max = audio.duration;

    music_text.innerHTML = text[curSong].text

    updateDurationDisplay();
});

// timeline o'zgarishi
let isSeeking = false;

timeline.addEventListener('mousedown', () => {
  isSeeking = true;
});

timeline.addEventListener('mouseup', () => {
  isSeeking = false;
  audio.currentTime = timeline.value;
});

timeline.addEventListener('input', () => {
  if (isSeeking) return;
  audio.currentTime = timeline.value;
});

audio.addEventListener('timeupdate', () => {
  if (!isSeeking) {
    timeline.value = audio.currentTime;
    updateDurationDisplay();
  }
});

// Play / Pause
const vinil = document.getElementById('vinil')
play.addEventListener('click', () => {    
    if (audio.paused) {
        vinil.classList.add("rotating")
        audio.play();
        play.textContent = '⏸';
    } else {
        vinil.classList.remove("rotating")
        audio.pause();
        play.textContent = '▶';
    }
})

// oldingi musiqa
prev.addEventListener('click', () => {
    if (curSong > 0) {
        curSong--;
        audio.setAttribute('src', songs[curSong].file);
        audio.play();
        play.textContent = '⏸';
    } else {
        curSong = songs.length - 1;
        audio.setAttribute('src', songs[curSong].file);
    }
})

// keyingi musiqa
next.addEventListener('click', () => {
    if (curSong < songs.length - 1) {
        curSong++;
        audio.setAttribute('src', songs[curSong].file);
        audio.play();
        play.textContent = '⏸';
    } else {
        curSong = 0;
        audio.setAttribute('src', songs[curSong].file);
    }
})

// musiqa tugashi
audio.addEventListener('ended', () => {
    console.log('Music ended');
    curSong++;
    audio.setAttribute('src', songs[curSong].file);
})

// vaqtini ko'rsatish
function formatTime(seconds) {
    const m = Math.floor(seconds / 60);
    const s = Math.floor(seconds % 60).toString().padStart(2, '0');
    return `${m}:${s}`;
}

function updateDurationDisplay() {
    const current = isNaN(audio.currentTime) ? 0 : audio.currentTime;
    const duration = isNaN(audio.duration) ? 0 : audio.duration;
    
    durationDisplay.textContent = `${formatTime(current)} / ${formatTime(duration) || 0}`
}

function musicPlay(element) {
    const music = Number(element.getAttribute("name"));
    curSong = music - 1
    audio.setAttribute('src', songs[curSong].file);
}

// Musiqa ro'yxatini ko'rsatish
const playlist = document.getElementById('playlist');

songs.map((song) => {
    const songContainer = document.createElement('div');
    songContainer.classList.add('song-container');
    songContainer.setAttribute("onclick", `musicPlay(this)`);
    songContainer.setAttribute("name", `${song.lyrics}`);
    
    const songImage = document.createElement('img');
    songImage.src = song.image;
    songImage.alt = song.title;
    songContainer.appendChild(songImage);

    const songInfo = document.createElement('div');
    songInfo.classList.add('song-info');
    
    const artist = document.createElement('p');
    artist.classList.add('artist');
    artist.textContent = `Artist: ${song.artist}`;
    songInfo.appendChild(artist);

    const title = document.createElement('h3');
    title.classList.add('title');
    title.textContent = song.title;
    songInfo.appendChild(title);

    const album = document.createElement('p');
    album.classList.add('album');
    album.textContent = `Album: ${song.album}`;
    songInfo.appendChild(album);

    const time = document.createElement('p');
    time.textContent = `Time: ${song.time}`;
    songInfo.appendChild(time);

    const icon = document.createElement('p');
    icon.classList.add('icon');
    icon.classList.add('glow-text');
    icon.textContent = "🎵";
    songInfo.appendChild(icon);

    songContainer.appendChild(songInfo);
    playlist.appendChild(songContainer);
})


