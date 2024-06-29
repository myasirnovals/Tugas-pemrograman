import React from "react";
import "../dist/css/keranjang.css";
import NavbarComponent from "../components/NavbarComponent";
import FooterComponent from "../components/FooterComponent";

const KeranjangPage = () => {
  const items = [
    {
      id: 1,
      name: "Produk 1",
      price: 50000,
      quantity: 2,
      image: "https://via.placeholder.com/100",
    },
    {
      id: 2,
      name: "Produk 2",
      price: 75000,
      quantity: 1,
      image: "https://via.placeholder.com/100",
    },
  ];

  const totalAmount = items.reduce((total, item) => total + item.price * item.quantity, 0);

  return (
    <div>
      <NavbarComponent />
      <div className="keranjang-page my-5">
        <h1>Keranjang Belanja</h1>
        <div className="items-list">
          {items.map((item) => (
            <div key={item.id} className="item">
              <img src={item.image} alt={item.name} />
              <div className="item-details">
                <h2>{item.name}</h2>
                <p>Rp{item.price.toLocaleString()}</p>
                <p>Jumlah: {item.quantity}</p>
              </div>
            </div>
          ))}
        </div>
        <div className="total">
          <h2>Total: Rp{totalAmount.toLocaleString()}</h2>
          <button className="checkout-button">Lanjutkan ke Pembayaran</button>
        </div>
      </div>
      <FooterComponent />
    </div>
  );
};

export default KeranjangPage;
