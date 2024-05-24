// DOM Selection
// document.getElemenById() -> elemen
const judul = document.getElementById("judul");
judul.style.color = "indigo";
judul.style.backgroundColor="darkgray";
judul.innerHTML = "Gary Roach Sanderson";

// document.getElementsByTagName() -> HTML
const p = document.getElementsByTagName("p");

for (let i = 0; i < p.length; i++) {
	p[i].style.backgroundColor = "maroon";
	p[i].style.color = "white";
}

const h1 = document.getElementsByTagName("h1")[0];
h1.style.fontSize = "15px";

// document.getElementsByClassName() -> HTML
const p1 = document.getElementsByClassName("p1")[0];
p1.innerHTML = "ini diubah melalui JavaScript";