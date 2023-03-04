import requests
import re

num = 1
dic = {}
head = {
        "User-Agent": "Mozilla / 5.0(Windows NT 10.0; Win64; x64) AppleWebKit / 537.36(KHTML, like Gecko) Chrome / 80.0.3987.122  Safari / 537.36"
    }

for x in range(1,144):
    url = "https://api.bilibili.com/x/web-interface/popular/series/one?number="+str(num)
    ge = requests.get(url,headers=head)
    ge.encoding = "utf-8"
    get = ge.text
    num += 1
    get.replace(" ","")
    content = re.findall(r'title\":\"(.*?)\"',get)
    target = re.findall(r'tname\":\"(.*?)\"',get)
    #match = re.complie(r'(.*)',)
    for s in target:
        if s in dic.keys():
            dic[s]+=1
        else:
            dic[s]=1
    print(url)

url2 = "https://api.bilibili.com/x/web-interface/ranking/v2?rid=0&type=all"

ge2 = requests.get(url2,headers=head)
ge2.encoding = "utf-8"
ge2t = ge2.text

ge2t.replace(" ","")
content2 = re.findall(r'title\":\"(.*?)\"',ge2t)
targe2t = re.findall(r'tname\":\"(.*?)\"',ge2t)
#match = re.complie(r'(.*)',)
for c in targe2t:
    if c in dic.keys():
        dic[c]+=1
    else:
        dic[c]=1
print(url2)

print(dic)