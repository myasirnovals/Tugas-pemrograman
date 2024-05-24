const p4 = document.querySelector("section#b p");
p4.addEventListener("click", function () {
    const ul = document.querySelector("section#b ul");
    const liBaru = document.createElement("li");
    const teskLiBaru = document.createTextNode("item baru!");

    liBaru.appendChild(teskLiBaru);
    ul.appendChild(liBaru);
});

const p3 = document.querySelector(".p3");
p3.onclick = function () {
    p3.style.color = "white";
}

p3.addEventListener("mouseenter", function () {
    p3.style.backgroundColor = "skyblue";
});

p3.addEventListener("mouseleave", function () {
    p3.style.backgroundColor = "grey";
});