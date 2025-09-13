import re
import requests
import json
import csv
import time
f=open('财富榜.csv','w',encoding='utf-8',newline='')
csv_writer=csv.DictWriter(f,fieldnames=['财富','姓名','主要公司','相关行业','省份','城市','性别','年龄'])
csv_writer.writeheader()

#发送请求
header={
'user-agent':
'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/130.0.0.0 Safari/537.36 Edg/130.0.0.0'
}
#网址
for page in range(1,35):
        print("正在爬取第{}页".format(page))
        #获取当前时间戳
        data_time=int(time.time()*1000)
        url=f'https://service.ikuyu.cn/XinCaiFu2/pcremoting/bdListAction.do?method=getPage&callback=jsonpCallback&sortBy=&order=&type=4&keyword=&pageSize=15&year=2024&pageNo={page}&from=jsonp&_={data_time}'

        #发送请求
        response=requests.get(url=url,headers=header)
        #获取text数据
        text=response.text


        #解析数据 是一个json数据
        info = re.findall('jsonpCallback\((.*)', text)[0][:-1]
        print(info)
        #将json数据转换为字典
        json_data=json.loads(info)
        #print(json_data)
        #根据键值对取值
        rows=json_data['data']['rows']
        for row in rows:
            dict={
                '财富': row['assets'],
                '姓名':row['name'],
                '主要公司':row['company'],
                '相关行业':row['industry'],
                '省份':row['addr'][:2],
                '城市':row['addr'][2:],
                '性别':row['sex'],
                '年龄':row['age'],
                  }
            csv_writer.writerow(dict)

