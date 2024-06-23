let cart = [];
let totalPrice = 0;

function addToCart(item, price) {
  cart.push({ item, price });
  totalPrice += price;
  updateCart();
}

function updateCart() {
  const cartItems = document.getElementById("cartItems");
  const total = document.getElementById("totalPrice");

  cartItems.innerHTML = "";
  cart.forEach((cartItem, index) => {
    const div = document.createElement("div");
    div.textContent = `${cartItem.item} - Rp.${cartItem.price} `;
    cartItems.appendChild(div);
  });

  total.textContent = totalPrice;
}

function checkout() {
  if (cart.length === 0) {
    alert("Anda belum order apapun");
    return;
  }

  fetch("process.php", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(cart),
  })
    .then((response) => response.json())
    .then((data) => {
      alert(data.message);
      cart = [];
      totalPrice = 0;
      updateCart();
    })
    .catch((error) => console.error("Error:", error));
}
