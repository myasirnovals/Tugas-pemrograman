import DataMakanan from "../assets/Blimart/Makanan/DataMakanan.json";
import * as Icon from "react-bootstrap-icons";

const Product = () => {
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
    <div responsive={responsive} className="container">
      <div id="carouselExampleAutoplaying" className="promotion carousel slide my-3" data-bs-ride="carousel">
        <div className="carousel-inner">
          <div className="carousel-item active">
            <img src="src/assets/Promotion banner/Banner 1.webp" className="banner rounded-5 d-block w-100" alt="banner-promotion" />
          </div>
          <div className="carousel-item">
            <img src="src/assets/Promotion banner/Banner 2.webp" className="banner rounded-5 d-block w-100" alt="banner-promotion" />
          </div>
          <div className="carousel-item">
            <img src="src/assets/Promotion banner/Banner 3.webp" className="banner rounded-5 d-block w-100" alt="banner-promotion" />
          </div>
          <div className="carousel-item">
            <img src="src/assets/Promotion banner/Banner 4.webp" className="banner rounded-5 d-block w-100" alt="banner-promotion" />
          </div>
          <div className="carousel-item">
            <img src="src/assets/Promotion banner/Banner 5.webp" className="banner rounded-5 d-block w-100" alt="banner-promotion" />
          </div>
          <div className="carousel-item">
            <img src="src/assets/Promotion banner/Banner 6.webp" className="banner rounded-5 d-block w-100" alt="banner-promotion" />
          </div>
          <div className="carousel-item">
            <img src="src/assets/Promotion banner/Banner 7.webp" className="banner rounded-5 d-block w-100" alt="banner-promotion" />
          </div>
        </div>
        <button className="carousel-control-prev" type="button" data-bs-target="#carouselExampleAutoplaying" data-bs-slide="prev">
          <Icon.ArrowLeftCircle size={30} className="arrow align-middle" />
          <span className="visually-hidden">Previous</span>
        </button>
        <button className="carousel-control-next" type="button" data-bs-target="#carouselExampleAutoplaying" data-bs-slide="next">
          <Icon.ArrowRightCircle size={30} className="arrow align-middle" />
          <span className="visually-hidden">Next</span>
        </button>
      </div>

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
  );
};

export default Product;