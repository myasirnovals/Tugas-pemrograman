const tUbahWarna = document.getElementById("tUbahWarna");

tUbahWarna.onclick = function () {
    document.body.classList.toggle("tomato");
}

const tAcakWarna = document.createElement("button");
const teksTombol = document.createTextNode("Acak warna");

tAcakWarna.appendChild(teksTombol);
tAcakWarna.setAttribute("type", "button");
tUbahWarna.after(tAcakWarna);

tAcakWarna.addEventListener("click", function () {
    const r = Math.round(Math.random() * 255 + 1);
    const g = Math.round(Math.random() * 255 + 1);
    const b = Math.round(Math.random() * 255 + 1);

    document.body.style.backgroundColor = "rgb(" + r + "," + g + "," + b + ")";
});

const sMerah = document.querySelector("input[name=sMerah]");
sMerah.addEventListener("input", function () {
    const r = sMerah.value;
    const g = sHijau.value;
    const b = sBiru.value;

    document.body.style.backgroundColor = "rgb(" + r + "," + g + "," + b + ")";
});

const sHijau = document.querySelector("input[name=sHijau]");
sHijau.addEventListener("input", function () {
    const r = sMerah.value;
    const g = sHijau.value;
    const b = sBiru.value;

    document.body.style.backgroundColor = "rgb(" + r + "," + g + "," + b + ")";
});

const sBiru = document.querySelector("input[name=sBiru]");
sBiru.addEventListener("input", function () {
    const r = sMerah.value;
    const g = sHijau.value;
    const b = sBiru.value;

    document.body.style.backgroundColor = "rgb(" + r + "," + g + "," + b + ")";
});


document.body.addEventListener("mousemove", function (event) {
    const xPos = Math.round((event.clientX / window.innerWidth) * 255);
    const yPos = Math.round((event.clientY / window.innerHeight) * 255);

    document.body.style.backgroundColor = "rgb(" + xPos + "," + yPos + ",100)";
});