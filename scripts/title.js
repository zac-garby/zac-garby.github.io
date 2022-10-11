var counts = {
    "A": 16,
    "B": 16,
    "C": 7,
    "G": 2,
    "R": 14,
    "Y": 4,
    "Z": 38,
}

function set(img, letter) {
    if (img.hidden) {
        var index = Math.floor(Math.random() * counts[letter]) + 1
        img.src = "/images/letters/" + letter + "/" + index + ".png"
        img.hidden = false
        img.style.transform = "rotate(" + (Math.random() * 8 - 4) + "deg)"
    }
}