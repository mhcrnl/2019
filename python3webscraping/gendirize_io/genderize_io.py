
import json
from requests import get

gender = get('https://api.genderize.io/?name=cornel')

result = json.loads(gender.text) 

print(result)
print(result["name"])
print(result["gender"])
print(result["probability"])
print(result["count"])


