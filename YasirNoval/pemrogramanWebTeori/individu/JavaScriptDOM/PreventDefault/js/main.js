// DOM Traversal
const close = document.querySelectorAll('.close');

close.forEach(function (el) {
    el.addEventListener('click', function (e) {
        e.target.parentElement.style.display = 'none';
        e.preventDefault();
    });
});