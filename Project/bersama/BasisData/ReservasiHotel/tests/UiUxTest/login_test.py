import unittest
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC


class LoginTest(unittest.TestCase):
    def setUp(self):
        # Inisialisasi webdriver (gunakan Chrome)
        self.driver = webdriver.Chrome()
        self.driver.maximize_window()
        # URL halaman login - sesuaikan dengan environment Anda
        self.base_url = "http://localhost/ReservasiHotel/src/pages/login/login.php"

    def tearDown(self):
        # Tutup browser setelah testing
        self.driver.quit()

    def test_login_page_elements(self):
        """Test untuk memverifikasi elemen-elemen pada halaman login"""
        driver = self.driver
        driver.get(self.base_url)

        # Verifikasi judul halaman
        self.assertEqual("Login - Sistem Reservasi Hotel", driver.title)

        # Verifikasi keberadaan elemen-elemen penting
        self.assertTrue(driver.find_element(By.ID, "username").is_displayed())
        self.assertTrue(driver.find_element(By.ID, "password").is_displayed())
        self.assertTrue(driver.find_element(By.NAME, "submit").is_displayed())

    def test_successful_login_admin(self):
        """Test untuk login sukses sebagai admin"""
        driver = self.driver
        driver.get(self.base_url)

        # Input credentials
        username = driver.find_element(By.ID, "username")
        password = driver.find_element(By.ID, "password")

        username.send_keys("admin1")  # Sesuaikan dengan credential yang valid
        password.send_keys("admin1234")  # Sesuaikan dengan credential yang valid

        # Klik tombol login
        driver.find_element(By.NAME, "submit").click()

        # Verifikasi redirect ke halaman dashboard admin
        WebDriverWait(driver, 10).until(
            EC.url_contains("/admin/dashboard/dashboard.php")
        )

    def test_successful_login_customer(self):
        """Test untuk login sukses sebagai customer"""
        driver = self.driver
        driver.get(self.base_url)

        username = driver.find_element(By.ID, "username")
        password = driver.find_element(By.ID, "password")

        username.send_keys("customer9")  # Sesuaikan dengan credential yang valid
        password.send_keys("customer9")  # Sesuaikan dengan credential yang valid

        driver.find_element(By.NAME, "submit").click()

        # Verifikasi redirect ke halaman index
        WebDriverWait(driver, 10).until(
            EC.url_contains("/index.php")
        )

    def test_failed_login(self):
        """Test untuk login gagal"""
        driver = self.driver
        driver.get(self.base_url)

        username = driver.find_element(By.ID, "username")
        password = driver.find_element(By.ID, "password")

        username.send_keys("invalid_user")
        password.send_keys("invalid_pass")

        driver.find_element(By.NAME, "submit").click()

        # Verifikasi pesan error
        error_message = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.CLASS_NAME, "alert-danger"))
        )
        self.assertIn("Username atau password salah!", error_message.text)

    def test_toggle_password_visibility(self):
        """Test untuk fungsi toggle password visibility"""
        driver = self.driver
        driver.get(self.base_url)

        password_field = driver.find_element(By.ID, "password")
        toggle_button = driver.find_element(By.ID, "togglePassword")

        # Verifikasi password tersembunyi awalnya
        self.assertEqual("password", password_field.get_attribute("type"))

        # Klik toggle button
        toggle_button.click()

        # Verifikasi password terlihat
        self.assertEqual("text", password_field.get_attribute("type"))

        # Klik toggle button lagi
        toggle_button.click()

        # Verifikasi password tersembunyi kembali
        self.assertEqual("password", password_field.get_attribute("type"))


if __name__ == "__main__":
    unittest.main()
