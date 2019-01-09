

from requests import get

ip = get('https://api.ipify.org').text

print ('Adresa de net este: {}'.format(ip))


