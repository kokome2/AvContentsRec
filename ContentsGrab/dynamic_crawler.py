from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from bs4 import BeautifulSoup

def fetch_content(url):
    options = webdriver.ChromeOptions()
    options.add_argument('--no-sandbox')
    options.add_argument('--headless')
    options.add_argument('--disable-dev-shm-usage')

    # Selenium을 사용하여 웹 페이지 가져오기
    with webdriver.Chrome(options=options) as driver:
        driver.get(url)
        
        # WebDriverWait를 사용하여 원하는 요소가 나타날 때까지 대기
        element = WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.CSS_SELECTOR, 'css_selector')))
        
        # 요소의 모든 속성 가져오기
        all_attributes = element.attrs
        print("All Attributes:", all_attributes)
    
    return content

if __name__ == "__main__":
    url = "https://www.avdbs.com"
    content = fetch_content(url)
    
    # BeautifulSoup를 사용하여 HTML 파싱
    soup = BeautifulSoup(content, 'html.parser')
    
    # 원하는 요소를 CSS 선택자로 찾기
    element = soup.select_one('css_selector')  # 실제 원하는 요소의 CSS 선택자로 대체해야 함
    
    if element:
        # 요소의 모든 속성 가져오기
        all_attributes = element.attrs
        print("All Attributes:", all_attributes)
    else:
        print("Element not found.")
