import requests
import re
import os
import jieba


dic = {}

num = 1
url2 = "https://api.bilibili.com/x/web-interface/ranking/region?rid=86&day=3&original=0&jsonp=jsonp&callback=jsonCallback_bili_261118115245816212"

ge2 = requests.get(url2)
ge2.encoding = "utf-8"
ge2t = ge2.text

ge2t.replace(" ","")

import os

with open('C:\programmming\project\gui.txt', encoding='utf-8') as file_obj:
    file = file_obj.read()


content2 = re.findall(r'title\":\"(.*?)\"',file)
targe2t = re.findall(r'tname\":\"(.*?)\"',file)

from wordcloud import WordCloud
clould = []
for x in content2:
    words = jieba.lcut(x)
    for word in words:
        clould.append(word)
        if word in dic.keys():
            dic[word]+=1
        else:
            dic[word]=1

text_cut  =  '/'.join(clould)
stopwords = ['我','的','了','の','是','岁','绿幕','素材','一个',"视频",'谁','说','一','向','鬼畜']
wordcd = WordCloud(background_color='white',font_path = 'msyh.ttc', width=1000, height=860, margin=2,stopwords=stopwords).generate(text_cut)
wordcd.to_file('鬼畜.png')
print(dic)