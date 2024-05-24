function getPilihanComputer() {
    var comp = Math.random();

    if (comp < 0.34) {
        return "batu";

    } else if (comp >= 0.34 && comp < 0.67) {
        return "gunting";

    } else {
        return "kertas";
    }
}

function getHasil(comp, player) {
    var hasil = "";

    if (player === comp) {
        return "Seri!";

    } else if (player === "batu") {
        if (comp === "gunting") {
            return "Menang";
        } else {
            return "Kalah";
        }

    } else if (player === "gunting") {
        if (comp === "kertas") {
            return "Menang";
        } else {
            return "Kalah";
        }

    } else if (player === "kertas") {
        if (comp === "batu") {
            return "Menang";
        } else {
            return "Kalah";
        }
    }
}

function putar() {
    const imgComputer = document.querySelector(".img-komputer");
    const gambar = ['batu', 'gunting', 'kertas'];

    let i = 0;
    const waktuMulai = new Date().getTime();
    setInterval(function () {
        if (new Date().getTime() - waktuMulai > 1000) {
            clearInterval;
            return;
        }

        imgComputer.setAttribute("src", "../Gambar/" + gambar[i++] + ".png");

        if (i === gambar.length) {
            i = 0;
        }

    }, 100);
}

const pilihan = document.querySelectorAll("li img");
pilihan.forEach(function (pil) {
    pil.addEventListener("click", function () {
        const pilihanComputer = getPilihanComputer();
        const pilihanPlayer = pil.className;
        const hasil = getHasil(pilihanComputer, pilihanPlayer);

        putar();

        setTimeout(function () {
            const imgComputer = document.querySelector(".img-komputer");
            imgComputer.setAttribute("src", "../Gambar/" + pilihanComputer + ".png");

            const info = document.querySelector(".info");
            info.innerHTML = hasil;
        }, 1000)

    })
})