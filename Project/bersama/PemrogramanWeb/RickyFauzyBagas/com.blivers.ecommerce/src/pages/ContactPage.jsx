import React from "react";
import "../dist/css/contactPage.css";
import NavbarComponent from "../components/NavbarComponent";

const ContactPage = () => {
  return (
    <div>
      <NavbarComponent />
      <div className="contact-page">
        <div className="contact-header">
          <h1>Contact Us</h1>
        </div>
        <div className="contact-info">
          <div className="contact-item">
            <h2>Customer Care</h2>
            <p>Phone: 0804-2-872-872</p>
            <p>Email: customer.care@bliver.com</p>
            <p>Hours: Monday - Sunday (24 Hours)</p>
          </div>
          <div className="contact-item">
            <h2>Business Inquiries</h2>
            <p>Email: business@bliver.com</p>
          </div>
        </div>
        <div className="contact-form">
          <h2>Get in Touch</h2>
          <form>
            <div className="form-group">
              <label htmlFor="name">Name</label>
              <input type="text" id="name" name="name" />
            </div>
            <div className="form-group">
              <label htmlFor="email">Email</label>
              <input type="email" id="email" name="email" />
            </div>
            <div className="form-group">
              <label htmlFor="message">Message</label>
              <textarea id="message" name="message"></textarea>
            </div>
            <button type="submit">Submit</button>
          </form>
        </div>
      </div>
    </div>
  );
};

export default ContactPage;
