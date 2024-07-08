let cart = [];
let totalPrice = 0;

function addToCart(item, price) {
    const existingItem = cart.find(cartItem => cartItem.item === item);
    if (existingItem) {
        existingItem.quantity++;
        existingItem.price += price;
    } else {
        cart.push({ item, price, quantity: 1 });
    }
    totalPrice += price;
    updateCart();
}

function removeFromCart(index) {
    const item = cart[index];
    totalPrice -= item.price / item.quantity;
    if (item.quantity > 1) {
        item.quantity--;
        item.price -= item.price / item.quantity;
    } else {
        cart.splice(index, 1);
    }
    updateCart();
}

function updateCart() {
    const cartItems = document.getElementById('cartItems');
    const total = document.getElementById('totalPrice');
    
    cartItems.innerHTML = '';
    cart.forEach((cartItem, index) => {
        const li = document.createElement('li');
        li.textContent = `${cartItem.item} - Rp.${cartItem.price} (x${cartItem.quantity})`;
        const removeButton = document.createElement('button');
        removeButton.textContent = 'Remove';
        removeButton.onclick = () => removeFromCart(index);
        li.appendChild(removeButton);
        cartItems.appendChild(li);
    });

    total.textContent = totalPrice;
}

function checkout() {
    if (cart.length === 0) {
        alert('Cart is empty!');
        return;
    }
    
    fetch('Process.php', {
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
