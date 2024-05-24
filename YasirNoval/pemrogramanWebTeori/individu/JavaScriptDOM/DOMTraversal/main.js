// DOM HTML
const phoneNumber = document.querySelectorAll('.telp');
let randomNumber = Math.floor((Math.random() * 9999999999) + 1000000000);
let codeNumber = "+";

for (const number of phoneNumber) {
    number.innerText = codeNumber.concat(randomNumber.toString());
}

// DOM Traversal
const close = document.querySelectorAll('.close');

close.forEach(function (el) {
    el.addEventListener('click', function (e) {
        e.target.parentElement.style.display = 'none';
    });
});

const nama = document.querySelector('.nama');
console.log(nama.nextElementSibling.nextElementSibling);