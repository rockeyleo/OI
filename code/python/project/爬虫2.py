import requests
import re
from wordcloud import WordCloud

lis = []
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
        lis.append(s)
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
    lis.append(c)
    if c in dic.keys():
        dic[c]+=1
    else:
        dic[c]=1
print(url2)

text_cut  =  '/'.join(lis)
stopwords = ['我','的',a'你','了','の','是','岁','绿幕','素材','一个']
wordcd = WordCloud(background_color='white',font_path = 'msyh.ttc', width=1000, height=860, margin=2,stopwords=stopwords).generate(text_cut)
wordcd.to_file('标签(2022.6.8).png')
#print(dic)