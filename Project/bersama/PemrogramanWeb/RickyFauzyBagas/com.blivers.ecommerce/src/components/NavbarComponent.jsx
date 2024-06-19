import { Container, Button, Nav, Navbar, NavDropdown, Form, Row, Col } from "react-bootstrap";
import * as Icon from "react-bootstrap-icons";
import "../dist/css/main.css";

const NavbarComponent = () => {
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
    <Navbar responsive={responsive} expand="xl" className="bg-body-white border">
      <Container>
        <Navbar.Brand href="/HomePage">
          <img alt="Blivers" src="src/assets/logo/logo-2.png" width="25" height="33" className="d-inline-block align-top" /> BliVers
        </Navbar.Brand>
        <Navbar.Toggle aria-controls="basic-navbar-nav" />
        <Navbar.Collapse id="basic-navbar-nav">
          <Nav className="me-auto">
            <NavDropdown title="Shop" id="basic-nav-dropdown">
              <Nav className="fw-bold ms-3 my-2">Blimart</Nav>
              <NavDropdown.Divider />
              <NavDropdown.Item href="/MakananPage">Makanan</NavDropdown.Item>
              <NavDropdown.Item href="/MinumanPage">Minuman</NavDropdown.Item>
              <NavDropdown.Item href="/BuahSayurPage">Buah & Sayur</NavDropdown.Item>
              <NavDropdown.Divider />
              <Nav className="fw-bold ms-3 my-2">Gadget & Elektronik</Nav>
              <NavDropdown.Divider />
              <NavDropdown.Item href="/HandphoneTabletPage">Handphone & Tablet</NavDropdown.Item>
              <NavDropdown.Item href="/KomputerGamingPage">Komputer & Gaming</NavDropdown.Item>
              <NavDropdown.Item href="/AlatElektronikPage">Alat Elektronik Lainnya</NavDropdown.Item>
              <NavDropdown.Divider />
              <Nav className="fw-bold ms-3 my-2">Fashion</Nav>
              <NavDropdown.Divider />
              <NavDropdown.Item href="/MenPage">Men's Fashion</NavDropdown.Item>
              <NavDropdown.Item href="/WomenPage">Women's Fashion</NavDropdown.Item>
              <NavDropdown.Item href="/KidPage">Kid's Fashion</NavDropdown.Item>
            </NavDropdown>
            <NavDropdown title="Pages" id="basic-nav-dropdown">
              <NavDropdown.Item href="/HomePage">Home</NavDropdown.Item>
              <NavDropdown.Item href="/KeranjangPage">Keranjang</NavDropdown.Item>
              <NavDropdown.Divider />
              <NavDropdown.Item href="/AkunPage">Akun</NavDropdown.Item>
            </NavDropdown>
            <Nav.Link href="/AlamatPage">Buku Alamat</Nav.Link>
            <Nav.Link href="/ContactPage">Contact</Nav.Link>
          </Nav>
        </Navbar.Collapse>
        <Form inline className="text-end">
          <Row>
            <Col xs="6">
              <Form.Control type="text" placeholder="Type for Search" className="mr-sm-2" />
            </Col>
            <Col>
              <Button variant="white" href="/AkunPage">
                <Icon.Person size={25} className="icon align-middle" />
              </Button>
            </Col>
            <Col>
              <Button variant="white" href="/KeranjangPage">
                <img alt="Blivers" src="src/assets/logo/keranjang-logo.svg" width="25" height="33" className="icon d-inline-block align-middle" />
              </Button>
            </Col>
          </Row>
        </Form>
      </Container>
    </Navbar>
  );
};

export default NavbarComponent;
