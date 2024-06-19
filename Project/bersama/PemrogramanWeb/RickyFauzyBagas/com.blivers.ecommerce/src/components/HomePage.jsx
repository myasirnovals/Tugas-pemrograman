import { Route, Routes } from "react-router-dom";
import Product from "../pages/Product";
import NavbarComponent from "./NavbarComponent";
import FooterComponent from "./FooterComponent";

const HomePage = () => {
  return (
    <div>
    <NavbarComponent/>
    <Routes>
      <Route path="/" Component={Product} />
      <Route path="/HomePage" Component={Product} />
    </Routes>
    <FooterComponent/>
    </div>
  );
};

export default HomePage;
