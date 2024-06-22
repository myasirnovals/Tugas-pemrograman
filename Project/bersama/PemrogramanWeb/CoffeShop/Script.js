let cart = [];
let totalPrice = 0;

function addToCart(item, price) {
    cart.push({ item, price });
    totalPrice += price;
    updateCart();
}

function updateCart() {
    const cartItems = document.getElementById('cartItems');
    const total = document.getElementById('totalPrice');
    
    cartItems.innerHTML = '';
    cart.forEach((cartItem, index) => {
        const li = document.createElement('li');
        li.textContent = `${cartItem.item} - RP.${cartItem.price} `;
        cartItems.appendChild(li);
    });

    total.textContent = totalPrice;
}

function checkout() {
    if (cart.length === 0) {
        alert('Cart is empty!');
        return;
    }
    
    fetch('process.php', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(cart)
    })
    .then(response => response.json())
    .then(data => {
        alert(data.message);
        cart = [];
        totalPrice = 0;
        updateCart();
    })
    .catch(error => console.error('Error:', error));
}
