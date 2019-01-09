"""
    author: mihai cornel mhcrnl@gmail.com
    run: python example_com.py
    program: test scraping the example.com site test 
    run: $ python example_com.py
    DOC: https://docs.python.org/3/library/urllib.request.html#module-urllib.request
        https://www.crummy.com/software/BeautifulSoup/bs4/doc/
"""
import urllib.request
from bs4 import BeautifulSoup
"""
    Read the url
"""
with urllib.request.urlopen('http://example.com/') as response:
    html = response.read()
"""
    On linux redirect the output to a file:
        $ command > textfile.txt
    to append data:
        $ command >> textfile.txt
    for stderr use this:
        $ command &> textfile.txt
    for append :
        $ command &>> textfile.txt
"""
soup = BeautifulSoup(html, 'html.parser')
"""
    Redirect output to a file: $ python example_com.py > txt_example.txt 
"""
#print(soup.prettify())
"""
    APPEND TO FILE:
    $ python example_com.py >> txt_example.txt
"""
print (soup.title)

print (soup.title.name)

print(soup.title.string)

print(soup.title.parent.name)

print(soup.p)

#print(soup.p['class'])

print (soup.a)

print(soup.find_all('a'))

print(soup.find(id="link"));

for link in soup.find_all('a'):
    print(link.get('href'))

print (soup.get_text())

print(soup.find_all('link', rel='stylesheet'))

print(list(soup.children))

print(soup.p.get_text())

"""
    NEXT: https://www.dataquest.io/blog/web-scraping-tutorial-python/
"""



