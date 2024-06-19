import { Routes, Route } from "react-router-dom";
import HomePage from "./components/HomePage";
import MakananPage from "./pages/MakananPage";
import MinumanPage from "./pages/MinumanPage";
import BuahSayurPage from "./pages/BuahSayurPage";
import HandphoneTabletPage from "./pages/HandphoneTabletPage";
import KomputerGamingPage from "./pages/KomputerGamingPage";
import AlatElektronikPage from "./pages/AlatElektronikPage";
import MenPage from "./pages/MenPage";
import WomenPage from "./pages/WomenPage";
import KidPage from "./pages/KidPage";
import KeranjangPage from "./pages/KeranjangPage";
import AkunPage from "./pages/AkunPage";
import AlamatPage from "./pages/AlamatPage";
import ContactPage from "./pages/ContactPage";
import "react-multi-carousel/lib/styles.css";
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.bundle.js";
import "./dist/css/main.css";

function App() {
  return (
    <div>
      <Routes>
        <Route path="/" Component={HomePage} />
        <Route path="/HomePage" Component={HomePage} />
        <Route path="/MakananPage" Component={MakananPage} />
        <Route path="/MinumanPage" Component={MinumanPage} />
        <Route path="/BuahSayurPage" Component={BuahSayurPage} />
        <Route path="/HandphoneTabletPage" Component={HandphoneTabletPage} />
        <Route path="/KomputerGamingPage" Component={KomputerGamingPage} />
        <Route path="/AlatElektronikPage" Component={AlatElektronikPage} />
        <Route path="/MenPage" Component={MenPage} />
        <Route path="/WomenPage" Component={WomenPage} />
        <Route path="/KidPage" Component={KidPage} />
        <Route path="/KeranjangPage" Component={KeranjangPage} />
        <Route path="/AkunPage" Component={AkunPage} />
        <Route path="/AlamatPage" Component={AlamatPage} />
        <Route path="/ContactPage" Component={ContactPage} />
      </Routes>
    </div>
  );
}

export default App;
