import NavbarComponent from "../components/NavbarComponent";
import FooterComponent from "../components/FooterComponent";
import Carousel from "react-multi-carousel";
import Kopi from "../assets/Blimart/Minuman/Kopi.json";
import Teh from "../assets/Blimart/Minuman/Teh.json";
import Susu from "../assets/Blimart/Minuman/Susu.json";
import DataMinuman from "../assets/Blimart/Minuman/DataMinuman.json";
import * as Icon from "react-bootstrap-icons";

const MinumanPage = () => {
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
        <div responsive={responsive} className="row row-cols-1 row-cols-md-4 g-4">
          {DataMinuman.map((DataMinuman) => {
            return (
              <div className="col-6 mt-4" key={DataMinuman.id}>
                <div className="card h-100">
                  <img src={DataMinuman.imageurl} className="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{DataMinuman.name}</p>
                    <p className="card-text fw-bold">{DataMinuman.price}</p>
                    <p className="card-text">{DataMinuman.description}</p>
                  </div>
                  <button className="btn btn-primary">
                    <Icon.CartPlus size={25} className="align-middle" />
                  </button>
                </div>
              </div>
            );
          })}
        </div>
        <br />

        <div className="card mb-4">
          <h4 className="mx-2 my-2">Product Kopi Terbaik</h4>
          <Carousel className="px-2 py-1 my-4" responsive={responsive}>
            {Kopi.map((Kopi) => {
              return (
                <div className="card h-100 mx-2" key={Kopi.id}>
                  <img src={Kopi.imageurl} class="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{Kopi.name}</p>
                    <p className="card-text fw-bold">{Kopi.price}</p>
                    <p className="card-text">{Kopi.description}</p>
                  </div>
                  <button className="btn btn-primary">
                    <Icon.CartPlus size={25} className="align-middle" />
                  </button>
                </div>
              );
            })}
          </Carousel>
        </div>

        <div className="card mb-4">
          <h4 className="mx-2 my-2">Product Teh Terbaik</h4>
          <Carousel className="px-2 py-1 my-4" responsive={responsive}>
            {Teh.map((Teh) => {
              return (
                <div className="card h-100 mx-2" key={Teh.id}>
                  <img src={Teh.imageurl} class="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{Teh.name}</p>
                    <p className="card-text fw-bold">{Teh.price}</p>
                    <p className="card-text">{Teh.description}</p>
                  </div>
                  <button className="btn btn-primary">
                    <Icon.CartPlus size={25} className="align-middle" />
                  </button>
                </div>
              );
            })}
          </Carousel>
        </div>

        <div className="card">
          <h4 className="mx-2 my-2">Product Susu Terbaik</h4>
          <Carousel className="px-2 py-1 my-4" responsive={responsive}>
            {Susu.map((Susu) => {
              return (
                <div className="card h-100 mx-2" key={Susu.id}>
                  <img src={Susu.imageurl} class="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{Susu.name}</p>
                    <p className="card-text fw-bold">{Susu.price}</p>
                    <p className="card-text">{Susu.description}</p>
                  </div>
                  <button className="btn btn-primary">
                    <Icon.CartPlus size={25} className="align-middle" />
                  </button>
                </div>
              );
            })}
          </Carousel>
        </div>
      </div>
      <FooterComponent />
    </div>
  );
};

export default MinumanPage;
