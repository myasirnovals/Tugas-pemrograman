import React from 'react';
import '../dist/css/akun.css';

const AkunPage = () => {
  return (
    <div className="akun-page">
      <header className="akun-header">
        <h1>Akun Saya</h1>
      </header>
      <main className="akun-main">
        <section className="akun-profile">
          <h2>Profil Saya</h2>
          <form className="akun-form">
            <div className="form-group">
              <label htmlFor="name">Nama</label>
              <input type="text" id="name" name="name" placeholder="Nama Anda" />
            </div>
            <div className="form-group">
              <label htmlFor="email">Email</label>
              <input type="email" id="email" name="email" placeholder="Email Anda" />
            </div>
            <div className="form-group">
              <label htmlFor="phone">Nomor Telepon</label>
              <input type="tel" id="phone" name="phone" placeholder="Nomor Telepon Anda" />
            </div>
            <button type="submit" className="btn-save">Simpan</button>
          </form>
        </section>
        <section className="akun-orders">
          <h2>Pesanan Saya</h2>
          {/* Contoh data pesanan */}
          <div className="order">
            <p>Pesanan #123456</p>
            <p>Status: Dikirim</p>
            <button className="btn-view">Lihat Detail</button>
          </div>
          <div className="order">
            <p>Pesanan #654321</p>
            <p>Status: Diproses</p>
            <button className="btn-view">Lihat Detail</button>
          </div>
        </section>
      </main>
    </div>
  );
};

export default AkunPage;
