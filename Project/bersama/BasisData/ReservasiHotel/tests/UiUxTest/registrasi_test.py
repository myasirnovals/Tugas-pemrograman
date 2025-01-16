import unittest
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.common.action_chains import ActionChains
import time


class RegistrationTest(unittest.TestCase):
    def setUp(self):
        service = Service(ChromeDriverManager().install())
        self.driver = webdriver.Chrome(service=service)
        self.driver.maximize_window()
        self.base_url = "http://localhost/ReservasiHotel/src/pages/registrasi/registrasi.php"

    def tearDown(self):
        self.driver.quit()

    def scroll_to_element(self, element):
        """Helper method untuk scroll ke element"""
        self.driver.execute_script("arguments[0].scrollIntoView(true);", element)
        time.sleep(0.5)  # Tunggu scroll selesai

    def test_registration_page_elements(self):
        """Test untuk memverifikasi semua elemen pada halaman registrasi"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Verifikasi judul halaman
        self.assertEqual("Registrasi - Sistem Reservasi Hotel", driver.title)

        # Verifikasi keberadaan form elements
        elements = {
            'username': (By.ID, 'username'),
            'email': (By.ID, 'email'),
            'password': (By.ID, 'password'),
            'confirm_password': (By.ID, 'confirm_password'),
            'nama_pelanggan': (By.ID, 'nama_pelanggan'),
            'no_hp': (By.ID, 'no_hp'),
            'jalan': (By.ID, 'jalan'),
            'desa': (By.ID, 'desa'),
            'kota': (By.ID, 'kota'),
            'provinsi': (By.ID, 'provinsi'),
            'kode_pos': (By.ID, 'kode_pos')
        }

        for element_name, locator in elements.items():
            element = wait.until(EC.presence_of_element_located(locator))
            self.assertTrue(element.is_displayed(), f"{element_name} tidak ditemukan")

    def test_successful_registration(self):
        """Test untuk registrasi berhasil"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Input data registrasi
        test_data = {
            'username': 'testuser124',
            'email': 'testuser124@example.com',
            'password': 'Password123',
            'confirm_password': 'Password123',
            'nama_pelanggan': 'Test User 4',
            'no_hp': '081234567890',
            'jalan': 'Jl. Test No. 123',
            'desa': 'Desa Test',
            'kota': 'Kota Test',
            'provinsi': 'Provinsi Test',
            'kode_pos': '12345'
        }

        for field_id, value in test_data.items():
            field = wait.until(EC.presence_of_element_located((By.ID, field_id)))
            self.scroll_to_element(field)
            field.clear()
            field.send_keys(value)

        # Submit form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, 'submit')))
        self.scroll_to_element(submit_button)
        driver.execute_script("arguments[0].click();", submit_button)

        # Tunggu redirect dengan timeout yang lebih lama
        try:
            # Tunggu URL berubah
            WebDriverWait(driver, 15).until(
                lambda driver: "login.php" in driver.current_url
            )
            # Verifikasi redirect ke halaman login
            self.assertIn("login.php", driver.current_url)
        except:
            self.fail("Redirect ke halaman login tidak terjadi")

    def test_password_mismatch(self):
        """Test untuk password yang tidak cocok"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Input semua field yang diperlukan
        test_data = {
            'username': 'testuser_mismatch',
            'email': 'mismatch@example.com',
            'nama_pelanggan': 'Test Mismatch',
            'no_hp': '081234567890',
            'jalan': 'Jl. Test No. 123',
            'desa': 'Desa Test',
            'kota': 'Kota Test',
            'provinsi': 'Provinsi Test',
            'kode_pos': '12345'
        }

        # Isi semua field kecuali password
        for field_id, value in test_data.items():
            field = wait.until(EC.presence_of_element_located((By.ID, field_id)))
            self.scroll_to_element(field)
            field.clear()
            field.send_keys(value)

        # Input password yang tidak cocok
        password = wait.until(EC.presence_of_element_located((By.ID, 'password')))
        confirm_password = wait.until(EC.presence_of_element_located((By.ID, 'confirm_password')))

        self.scroll_to_element(password)
        password.send_keys('Password123')

        self.scroll_to_element(confirm_password)
        confirm_password.send_keys('DifferentPassword123')

        # Submit form
        submit_button = driver.find_element(By.NAME, 'submit')
        self.scroll_to_element(submit_button)

        # Gunakan JavaScript untuk click
        driver.execute_script("arguments[0].click();", submit_button)

        # Tunggu pesan error muncul dengan timeout yang lebih lama
        try:
            error_message = WebDriverWait(driver, 15).until(
                EC.presence_of_element_located((By.CLASS_NAME, 'alert-danger'))
            )
            self.assertIn("Password tidak cocok!", error_message.text)
        except:
            self.fail("Pesan error 'Password tidak cocok!' tidak muncul")

    def test_duplicate_username(self):
        """Test untuk username yang sudah terdaftar"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        test_data = {
            'username': 'admin1',
            'email': 'newtest@example.com',
            'password': 'Password123',
            'confirm_password': 'Password123',
            'nama_pelanggan': 'Test User',
            'no_hp': '081234567890',
            'jalan': 'Jl. Test No. 123',
            'desa': 'Desa Test',
            'kota': 'Kota Test',
            'provinsi': 'Provinsi Test',
            'kode_pos': '12345'
        }

        for field_id, value in test_data.items():
            field = wait.until(EC.presence_of_element_located((By.ID, field_id)))
            self.scroll_to_element(field)
            field.clear()
            field.send_keys(value)

        # Submit form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, 'submit')))
        self.scroll_to_element(submit_button)
        ActionChains(driver).move_to_element(submit_button).click().perform()

        # Verifikasi pesan error
        error_message = wait.until(EC.presence_of_element_located((By.CLASS_NAME, 'alert-danger')))
        self.assertIn("Username sudah digunakan!", error_message.text)

    def test_required_fields(self):
        """Test untuk memverifikasi field yang wajib diisi"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Submit form kosong
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, 'submit')))
        self.scroll_to_element(submit_button)
        ActionChains(driver).move_to_element(submit_button).click().perform()

        # Verifikasi HTML5 validation
        required_fields = ['username', 'email', 'password', 'confirm_password',
                           'nama_pelanggan', 'no_hp', 'jalan', 'desa', 'kota',
                           'provinsi', 'kode_pos']

        for field_id in required_fields:
            element = driver.find_element(By.ID, field_id)
            self.assertTrue(element.get_attribute('required'))


if __name__ == "__main__":
    unittest.main()
