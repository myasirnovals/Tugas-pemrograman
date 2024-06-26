import NavbarComponent from "../components/NavbarComponent";
import FooterComponent from "../components/FooterComponent";
import DataKidFashion from "../assets/Fashion-Beauty/KidFashion/DataKidFashion.json";
import * as Icon from "react-bootstrap-icons";

const KidPage = () => {
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
          {DataKidFashion.map((DataKidFashion) => {
            return (
              <div className="col-6 mt-4" key={DataKidFashion.id}>
                <div className="card h-100">
                  <img src={DataKidFashion.imageurl} className="card-img-top" alt="Product" />
                  <div className="card-body">
                    <p className="card-title">{DataKidFashion.name}</p>
                    <p className="card-text fw-bold">{DataKidFashion.price}</p>
                    <p className="card-text">{DataKidFashion.description}</p>
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

export default KidPage;
