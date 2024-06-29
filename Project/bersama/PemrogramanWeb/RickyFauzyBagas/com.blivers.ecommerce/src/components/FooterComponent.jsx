import { Container, Row, Col } from "react-bootstrap";
import { Link } from "react-router-dom";
import * as Icon from "react-bootstrap-icons";
import "../dist/css/main.css";

const FooterComponent = () => {
  const responsive = {
    superLargeDesktop: {
      breakpoint: { max: 4000, min: 1024 },
      items: 5,
    },
    desktop: {
      breakpoint: { max: 1024, min: 800 },
      items: 4,
    },
    tablet: {
      breakpoint: { max: 800, min: 464 },
      items: 2,
    },
    mobile: {
      breakpoint: { max: 464, min: 0 },
      items: 1,
    },
  };

  return (
    <div className="footer py-5">
      <Container responsive={responsive}>
        <Row className="d-flex justify-content-between">
          <Col lg="5">
            <h3 className="fw-bold">BliVers</h3>
            <p className="desc">
              Sebagai mal online terbesar dan terpercaya, BliVers menawarkan berbagai pilihan produk berkualitas yang disediakan oleh lebih dari 100.000 mitra usaha, mulai dari kebutuhan primer, produk elektronik termasuk gadget, kebutuhan
              sehari-hari hingga produk untuk keperluan gaya hidup.
              <br /> <br />
              BliVers adalah e-commerce Indonesia yang menyediakan berbagai macam kebutuhan serta produk pilihan yang 100% Orisinil, pengiriman Cepat dan Gratis Ongkir, menyediakan layanan Customer Service 24 Jam bagi konsumen, transaksi
              belanja online dan Pembayaran Aman, 15 hari retur produk dan layanan pembayaran Cash On Delivery langsung di rumahmu.
            </p>
            <Col className="no mb-1 mt-4">
              <h5 className="fw-bold">Customer Care</h5>
              <Link className="text-decoration-none">
                <Icon.Whatsapp />
                <p className="m-0">0804-2-872-872</p>
              </Link>
            </Col>
            <div className="mail">
              <Link className="text-decoration-none">
                <Icon.Envelope />
                <p className="m-0">customer.care@blivers.com</p>
              </Link>
            </div>
          </Col>
          <Col className="d-flex flex-column col-lg-2 col mt-lg-0 mt-5">
            <h5 className="fw-bold">Menu</h5>
            <Link to="/HomePage">Home</Link>
            <Link to="/AkunPage">Akun</Link>
            <Link to="/ContactPage">Contact</Link>
          </Col>
          <Col lg="2" className="mt-lg-0 mt-5">
            <h5 className="fw-bold mb-3">Ikuti Kami</h5>
            <div className="social mt-3">
              <Link className="i">
                <Icon.Facebook />
              </Link>
              <Link className="i">
                <Icon.Instagram />
              </Link>
              <Link className="i">
                <Icon.TwitterX />
              </Link>
              <Link className="i">
                <Icon.Youtube />
              </Link>
            </div>
          </Col>
        </Row>
        <hr />
        <Row>
          <Col>
            <p className="px-md-0 px-3 fw-bold">BliVers &copy; {new Date().getFullYear()} | Toko online dengan sensasi belanja ala mall</p>
          </Col>
        </Row>
      </Container>
    </div>
  );
};

export default FooterComponent;
