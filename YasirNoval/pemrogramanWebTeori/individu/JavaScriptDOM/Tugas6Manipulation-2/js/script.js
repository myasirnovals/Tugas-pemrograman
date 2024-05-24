const pBaru = document.createElement("p");
const teksBaru = document.createTextNode("Paragraf baru");

pBaru.appendChild(teksBaru);

const sectionA = document.getElementById("a");
sectionA.appendChild(pBaru);

const liBaru = document.createElement("li");
const teskLiBaru = document.createTextNode("Item Baru");
liBaru.appendChild(teskLiBaru);

const ul = document.querySelector("section#b ul");
const li2 = ul.querySelector("li:nth-child(2)");
ul.insertBefore(liBaru, li2);

const link = document.getElementsByTagName("a")[0];
sectionA.removeChild(link);

const sectionB = document.getElementById("b");
const p4 = sectionB.querySelector("p");

const h2Baru = document.createElement("h2");
const teskH2Baru = document.createTextNode("Judul Baru!");

h2Baru.appendChild(teskH2Baru);

sectionB.replaceChild(h2Baru, p4);

pBaru.style.backgroundColor = "indigo"
pBaru.style.color = "white"

liBaru.style.backgroundColor = "indigo"
liBaru.style.color = "white"

h2Baru.style.backgroundColor = "indigo"
h2Baru.style.color = "white"