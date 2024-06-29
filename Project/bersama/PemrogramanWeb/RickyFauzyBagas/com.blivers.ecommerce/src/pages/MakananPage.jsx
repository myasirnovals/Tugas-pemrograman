import NavbarComponent from "../components/NavbarComponent";
import FooterComponent from "../components/FooterComponent";
import Carousel from "react-multi-carousel";
import Sembako from "../assets/Blimart/Makanan/Sembako.json";
import MieInstan from "../assets/Blimart/Makanan/MieInstan.json";
import Snack from "../assets/Blimart/Makanan/Snack.json";
import DataMakanan from "../assets/Blimart/Makanan/DataMakanan.json";
import * as Icon from "react-bootstrap-icons";

const MakananPage = () => {
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
        <h5 className="container my-2">Sembako</h5>
        <Carousel className="px-2 py-1" responsive={responsive}>
          <div className="card">
            <img src="src/assets/Blimart/Banner/Sembako.webp" class="card-img-top rounded-1" alt="Banner" />
          </div>
          {Sembako.map((Sembako) => {
            return (
              <div className="card mx-2" key={Sembako.id}>
                <img src={Sembako.imageurl} class="card-img-top" alt="Product" />
                <div className="card-body">
                  <p className="card-title">{Sembako.name}</p>
                  <p className="card-text text-secondary">{Sembako.price}</p>
                  <p className="card-text">{Sembako.description}</p>
                </div>
                <button className="btn btn-primary">
                  <Icon.CartPlus size={25} className="align-middle" />
                </button>
              </div>
            );
          })}
        </Carousel>

        <h5 className="container my-2">Mie Instan</h5>
        <Carousel className="px-2 py-1" responsive={responsive}>
          <div className="card">
            <img src="src/assets/Blimart/Banner/Mie Instan.webp" class="card-img-top rounded-1" alt="Banner" />
          </div>
          {MieInstan.map((MieInstan) => {
            return (
              <div className="card mx-2" key={MieInstan.id}>
                <img src={MieInstan.imageurl} class="card-img-top" alt="Product" />
                <div className="card-body">
                  <p className="card-title">{MieInstan.name}</p>
                  <p className="card-text text-secondary">{MieInstan.price}</p>
                  <p className="card-text">{MieInstan.description}</p>
                </div>
                <button className="btn btn-primary">
                  <Icon.CartPlus size={25} className="align-middle" />
                </button>
              </div>
            );
          })}
        </Carousel>

        <h5 className="container my-2">Snack</h5>
        <Carousel className="px-2 py-1" responsive={responsive}>
          <div className="card">
            <img src="src/assets/Blimart/Banner/Snack.webp" class="card-img-top rounded-1" alt="Banner" />
          </div>
          {Snack.map((Snack) => {
            return (
              <div className="card mx-2" key={Snack.id}>
                <img src={Snack.imageurl} class="card-img-top" alt="Product" />
                <div className="card-body">
                  <p className="card-title">{Snack.name}</p>
                  <p className="card-text text-secondary">{Snack.price}</p>
                  <p className="card-text">{Snack.description}</p>
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
          {DataMakanan.map((DataMakanan) => {
            return (
              <div className="col-6 mt-4" key={DataMakanan.id}>
                <div className="card">
                  <img src={DataMakanan.imageurl} className="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{DataMakanan.name}</p>
                    <p className="card-text text-secondary">{DataMakanan.price}</p>
                    <p className="card-text">{DataMakanan.description}</p>
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

export default MakananPage;
