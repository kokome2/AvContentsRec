import requests
from bs4 import BeautifulSoup

def main():
    # 웹 사이트 URL
    url = "https://www.avdbs.com/menu/actor.php?actor_idx=4428"

    # User-Agent 설정
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36'
    }

    # 요청 보내기
    response = requests.get(url, headers=headers)

    # 상태 코드 확인
    if response.status_code == 200:
        # 요청이 성공한 경우
        content = response.text
        
        # BeautifulSoup을 사용하여 HTML 파싱
        soup = BeautifulSoup(content, 'html.parser')
        
        # 배우의 이름 추출
        actor_name_element = soup.find(class_='k_name highlight')
        if actor_name_element:
            actor_name = actor_name_element.text.strip()
        else:
            actor_name = "Actor name not found"

if __name__ == "__main__":
    main()
