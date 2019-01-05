"""
    author: mihai cornel mhcrnl@gmail.com
    run: python example_com.py
    program: test scraping the example.com site test 
"""
import urllib.request
from bs4 import BeautifulSoup
"""
    Read the url
"""
with urllib.request.urlopen('http://example.com/') as response:
    html = response.read()
"""
    
"""
soup = BeautifulSoup(html, 'html.parser')

print(soup.prettify())
