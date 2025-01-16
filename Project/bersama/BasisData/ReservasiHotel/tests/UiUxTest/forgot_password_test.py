import unittest
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.service import Service
import time


class TestForgotPassword(unittest.TestCase):
    def setUp(self):
        """Setup untuk setiap test case"""
        service = Service(ChromeDriverManager().install())
        self.driver = webdriver.Chrome(service=service)
        self.base_url = "http://localhost/ReservasiHotel/src/pages/login/forgot-password.php"
        self.driver.maximize_window()

    def tearDown(self):
        """Cleanup setelah setiap test case"""
        if self.driver:
            self.driver.quit()

    def test_page_elements(self):
        """Test keberadaan dan properti elemen-elemen di halaman forgot password"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Verifikasi judul halaman
        self.assertEqual("Lupa Password - Sistem Reservasi Hotel", driver.title)

        # Verifikasi elemen-elemen dan propertinya
        elements = {
            'heading': {
                'locator': (By.XPATH, "//h3[contains(text(), 'Lupa Password')]"),
                'text': 'Lupa Password'
            },
            'username_label': {
                'locator': (By.XPATH, "//label[@for='username']"),
                'text': 'Username'
            },
            'username_input': {
                'locator': (By.ID, 'username'),
                'type': 'text',
                'required': True
            },
            'email_label': {
                'locator': (By.XPATH, "//label[@for='email']"),
                'text': 'Email'
            },
            'email_input': {
                'locator': (By.ID, 'email'),
                'type': 'email',
                'required': True
            },
            'submit_button': {
                'locator': (By.NAME, 'submit'),
                'text': 'Reset Password'
            },
            'back_link': {
                'locator': (By.XPATH, "//a[contains(text(), 'Kembali ke Login')]"),
                'text': 'Kembali ke Login'
            }
        }

        # Verifikasi setiap elemen
        for element_name, properties in elements.items():
            element = wait.until(EC.presence_of_element_located(properties['locator']))
            self.assertTrue(element.is_displayed(), f"{element_name} tidak terlihat")

            # Verifikasi teks jika ada
            if 'text' in properties:
                self.assertEqual(properties['text'], element.text)

            # Verifikasi tipe input jika ada
            if 'type' in properties:
                self.assertEqual(properties['type'], element.get_attribute('type'))

            # Verifikasi required attribute jika ada
            if 'required' in properties:
                self.assertEqual('true', element.get_attribute('required'))

    def test_empty_form_submission(self):
        """Test submit form kosong"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Klik submit tanpa mengisi form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, "submit")))
        submit_button.click()

        # Verifikasi form tidak tersubmit (HTML5 validation)
        username_input = driver.find_element(By.ID, "username")
        self.assertEqual(username_input, driver.switch_to.active_element)

    def test_invalid_email_format(self):
        """Test submit dengan format email tidak valid"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Isi username dan email tidak valid
        username_field = wait.until(EC.presence_of_element_located((By.ID, "username")))
        email_field = wait.until(EC.presence_of_element_located((By.ID, "email")))

        username_field.send_keys("testuser")
        email_field.send_keys("invalid-email")

        # Submit form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, "submit")))
        submit_button.click()

        # Verifikasi email field invalid
        self.assertFalse(email_field.get_attribute("validity").get("valid"))

    def test_nonexistent_user(self):
        """Test dengan username yang tidak terdaftar"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Isi form dengan data yang tidak terdaftar
        username_field = wait.until(EC.presence_of_element_located((By.ID, "username")))
        email_field = wait.until(EC.presence_of_element_located((By.ID, "email")))

        username_field.send_keys("nonexistentuser")
        email_field.send_keys("nonexistent@email.com")

        # Submit form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, "submit")))
        submit_button.click()

        # Verifikasi pesan error
        error_message = wait.until(EC.presence_of_element_located((By.CLASS_NAME, "alert-danger")))
        self.assertIn("Username atau email tidak ditemukan!", error_message.text)

    def test_valid_user_submission(self):
        """Test dengan data valid (username dan email yang terdaftar)"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Isi form dengan data valid
        username_field = wait.until(EC.presence_of_element_located((By.ID, "username")))
        email_field = wait.until(EC.presence_of_element_located((By.ID, "email")))

        username_field.send_keys("customer1")  # Sesuaikan dengan data di database
        email_field.send_keys("budi@email.com")  # Sesuaikan dengan data di database

        # Submit form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, "submit")))
        submit_button.click()

        # Verifikasi redirect ke halaman reset password
        self.assertIn("reset-password.php", driver.current_url)

    def test_back_to_login(self):
        """Test link kembali ke halaman login"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Klik link kembali ke login
        back_link = wait.until(EC.element_to_be_clickable(
            (By.XPATH, "//a[contains(text(), 'Kembali ke Login')]")
        ))
        back_link.click()

        # Verifikasi redirect ke halaman login
        self.assertIn("login.php", driver.current_url)

    def test_form_persistence(self):
        """Test persistensi data form setelah submit gagal"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Isi form dengan data yang tidak valid
        username_field = wait.until(EC.presence_of_element_located((By.ID, "username")))
        email_field = wait.until(EC.presence_of_element_located((By.ID, "email")))

        test_username = "testuser123"
        test_email = "test@email.com"

        username_field.send_keys(test_username)
        email_field.send_keys(test_email)

        # Submit form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, "submit")))
        submit_button.click()

        # Verifikasi data form masih ada setelah error
        self.assertEqual(test_username, username_field.get_attribute('value'))
        self.assertEqual(test_email, email_field.get_attribute('value'))

    def test_xss_prevention(self):
        """Test pencegahan XSS pada form"""
        driver = self.driver
        driver.get(self.base_url)
        wait = WebDriverWait(driver, 10)

        # Isi form dengan script injection
        username_field = wait.until(EC.presence_of_element_located((By.ID, "username")))
        email_field = wait.until(EC.presence_of_element_located((By.ID, "email")))

        xss_script = "<script>alert('xss')</script>"
        username_field.send_keys(xss_script)
        email_field.send_keys("test@email.com")

        # Submit form
        submit_button = wait.until(EC.element_to_be_clickable((By.NAME, "submit")))
        submit_button.click()

        # Verifikasi tidak ada alert yang muncul
        try:
            alert = driver.switch_to.alert
            alert.accept()
            self.fail("XSS attack berhasil - alert ditemukan")
        except:
            pass  # Test berhasil jika tidak ada alert


if __name__ == '__main__':
    unittest.main(verbosity=2)
