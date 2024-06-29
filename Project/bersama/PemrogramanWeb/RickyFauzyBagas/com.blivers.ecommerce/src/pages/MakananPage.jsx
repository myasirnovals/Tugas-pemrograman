import NavbarComponent from "../components/NavbarComponent";
import FooterComponent from "../components/FooterComponent";
import Carousel from "react-multi-carousel";
import Minyak from "../assets/Blimart/Makanan/Minyak.json";
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
        <Carousel className="px-2 py-1 my-4" responsive={responsive}>
          <div className="card border-none h-100">
            <img src="src/assets/Blimart/Makanan/Minyak Goreng.avif" class="card-img-top rounded-4" alt="Banner" height={"100%"}/>
          </div>
          {Minyak.map((Minyak) => {
            return (
              <div className="card h-100 mx-2" key={Minyak.id}>
                <img src={Minyak.imageurl} class="card-img-top" alt="Product" />
                <div className="card-body">
                  <p className="card-title">{Minyak.name}</p>
                  <p className="card-text fw-bold">{Minyak.price}</p>
                  <p className="card-text">{Minyak.description}</p>
                </div>
                <button className="btn btn-primary">
                  <Icon.CartPlus size={25} className="align-middle" />
                </button>
              </div>
            );
          })}
        </Carousel>

        <Carousel className="px-2 py-1 my-4" responsive={responsive}>
          <div className="card border-none h-100">
            <img src="src/assets/Blimart/Makanan/Mie Instan.avif" class="card-img-top rounded-4" alt="Banner" height={"100%"}/>
          </div>
          {MieInstan.map((MieInstan) => {
            return (
              <div className="card h-100 mx-2" key={MieInstan.id}>
                <img src={MieInstan.imageurl} class="card-img-top" alt="Product" />
                <div className="card-body">
                  <p className="card-title">{MieInstan.name}</p>
                  <p className="card-text fw-bold">{MieInstan.price}</p>
                  <p className="card-text">{MieInstan.description}</p>
                </div>
                <button className="btn btn-primary">
                  <Icon.CartPlus size={25} className="align-middle" />
                </button>
              </div>
            );
          })}
        </Carousel>

        <Carousel className="px-2 py-1 my-4" responsive={responsive}>
          <div className="card border-none h-100">
            <img src="src/assets/Blimart/Makanan/Snack.avif" class="card-img-top rounded-4" alt="Banner" height={"100%"}/>
          </div>
          {Snack.map((Snack) => {
            return (
              <div className="card h-100 mx-2" key={Snack.id}>
                <img src={Snack.imageurl} class="card-img-top" alt="Product" />
                <div className="card-body">
                  <p className="card-title">{Snack.name}</p>
                  <p className="card-text fw-bold">{Snack.price}</p>
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
                <div className="card h-100">
                  <img src={DataMakanan.imageurl} className="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{DataMakanan.name}</p>
                    <p className="card-text fw-bold">{DataMakanan.price}</p>
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
