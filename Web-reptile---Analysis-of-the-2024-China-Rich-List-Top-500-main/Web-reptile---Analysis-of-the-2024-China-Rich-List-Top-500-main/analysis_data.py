import pandas as pd
# 导入配置项
from pyecharts import options as opts
# 导入饼图
from pyecharts.charts import Pie
# 读取csv文件
df = pd.read_csv('财富榜.csv')
print(df.head())
# 统计相关数据
x = df['省份'].value_counts().index.to_list()
y = df['省份'].value_counts().to_list()
c = (
    Pie()
    .add(
        "",
        [
            list(z)
            for z in zip(
                x,
                y,
            )
        ],
        center=["40%", "50%"],
    )
    .set_global_opts(
        title_opts=opts.TitleOpts(title="富豪榜Top500公司地区分布情况"),
        legend_opts=opts.LegendOpts(type_="scroll", pos_left="80%", orient="vertical"),
    )
    .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
    .render("pie_富豪榜Top500公司地区分布情况.html")
)

x_gd = df.groupby('省份')['城市'].value_counts()['广东'].index.to_list()
y_gd = df.groupby('省份')['城市'].value_counts()['广东'].to_list()
c_gd = (
    Pie()
    .add(
        "",
        [
            list(z)
            for z in zip(
                x_gd,
                y_gd,
            )
        ],
        center=["40%", "50%"],
    )
    .set_global_opts(
        title_opts=opts.TitleOpts(title="富豪榜Top500公司广东省地区分布情况"),
        legend_opts=opts.LegendOpts(type_="scroll", pos_left="80%", orient="vertical"),
    )
    .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
    .render("pie_富豪榜Top500公司广东省地区分布情况.html")
)

x_sex = df['性别'].value_counts().index.to_list()
y_sex = df['性别'].value_counts().to_list()
c_sex = (
    Pie()
    .add(
        "",
        [
            list(z)
            for z in zip(
                x_sex,
                y_sex,
            )
        ],
        center=["40%", "50%"],
    )
    .set_global_opts(
        title_opts=opts.TitleOpts(title="富豪榜Top500公司性别分布情况"),
        legend_opts=opts.LegendOpts(type_="scroll", pos_left="80%", orient="vertical"),
    )
    .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
    .render("pie_富豪榜Top500公司性别分布情况.html")
)
