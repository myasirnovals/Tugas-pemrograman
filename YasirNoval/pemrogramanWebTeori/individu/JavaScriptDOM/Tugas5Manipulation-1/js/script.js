const judul = document.getElementById("judul");

judul.style.color = "white";
judul.style.background = "maroon";
judul.innerHTML = "<i>Gary Roach Sanderson</i>";

const sectionA = document.querySelector("section#a");
sectionA.innerHTML = "<div><p>paragraf1</p></div>";

const p2 = document.querySelector(".p2");
p2.setAttribute("class", "link");