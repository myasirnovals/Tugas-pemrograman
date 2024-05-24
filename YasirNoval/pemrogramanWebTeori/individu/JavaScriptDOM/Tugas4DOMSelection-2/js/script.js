// document.querySelector() -> element
const li2 = document.querySelector("section#b ul li:nth-child(2)");
li2.style.backgroundColor = "skyblue";

// document.querySelectorAll()
const p = document.querySelectorAll("p");

for (let i = 0; i < p.length; i++) {
    p[i].style.backgroundColor = "magenta";
    p[i].style.color = "white";
}


// Mengubah Node Root
const sectionB = document.querySelector("section#b");
const p4 = sectionB.getElementsByTagName("p")[0];
p4.style.backgroundColor = "darkred";