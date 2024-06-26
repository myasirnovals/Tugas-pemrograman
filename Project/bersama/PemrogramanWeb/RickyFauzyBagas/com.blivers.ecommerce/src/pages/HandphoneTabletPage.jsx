import NavbarComponent from "../components/NavbarComponent";
import FooterComponent from "../components/FooterComponent";
import Carousel from "react-multi-carousel";
import ProductBanner from "../assets/Gadget-Elektronik/Handphone-Tablet/ProductBanner.json";
import DataPhoneTablet from "../assets/Gadget-Elektronik/Handphone-Tablet/DataPhoneTablet.json";
import * as Icon from "react-bootstrap-icons";

const HandphoneTabletPage = () => {
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
    <div>
      <NavbarComponent />
      <div responsive={responsive} className="container my-3">
        <Carousel className="bg-ht px-2 py-2 my-1" responsive={responsive}>
          <div className="card border-none h-100">
            <img src="src/assets/Gadget-Elektronik/Handphone-Tablet/Banner.webp" class="card-img-top rounded-1" alt="Banner" height={"100%"} />
          </div>
          {ProductBanner.map((ProductBanner) => {
            return (
              <div className="card border-none h-100 mx-2" key={ProductBanner.id}>
                <img src={ProductBanner.imageurl} class="card-img-top" alt="Product" />
                <div className="card-body">
                  <p className="card-title">{ProductBanner.name}</p>
                  <p className="card-text fw-bold">{ProductBanner.price}</p>
                  <p className="card-text">{ProductBanner.description}</p>
                </div>
                <button className="btn btn-primary">
                  <Icon.CartPlus size={25} className="align-middle" />
                </button>
              </div>
            );
          })}
        </Carousel>
        <br />

        <div responsive={responsive} className="row row-cols-1 row-cols-md-4 g-4">
          {DataPhoneTablet.map((DataPhoneTablet) => {
            return (
              <div className="col-6 mt-4" key={DataPhoneTablet.id}>
                <div className="card h-100">
                  <img src={DataPhoneTablet.imageurl} className="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{DataPhoneTablet.name}</p>
                    <p className="card-text fw-bold">{DataPhoneTablet.price}</p>
                    <p className="card-text">{DataPhoneTablet.description}</p>
                  </div>
                  <button className="btn btn-primary">
                    <Icon.CartPlus size={25} className="align-middle" />
                  </button>
                </div>
              </div>
            );
          })}
        </div>
      </div>
      <FooterComponent />
    </div>
  );
};

export default HandphoneTabletPage;
