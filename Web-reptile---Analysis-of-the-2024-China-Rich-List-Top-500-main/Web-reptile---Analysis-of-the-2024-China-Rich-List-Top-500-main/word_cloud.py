import pandas as pd
import jieba
from wordcloud import WordCloud
import matplotlib.pyplot as plt

# 文件路径
file_path = r"D:\code\杂\Reptile\财富榜.csv"

# 加载数据
data = pd.read_csv(file_path, encoding="utf-8")

# 选择需要生成词云的字段，如“相关行业”字段
text = " ".join(data["相关行业"].dropna())

# 使用 jieba 分词
seg_list = jieba.cut(text, cut_all=False)
seg_text = " ".join(seg_list)

# 设置词云配置
wc = WordCloud(
    font_path="simhei.ttf",  # 字体路径，确保支持中文
    background_color="white",  # 背景颜色
    width=800,
    height=600,
    max_words=200,  # 最大显示单词数
    colormap="viridis"  # 颜色样式
)

# 生成词云
wordcloud = wc.generate(seg_text)

# 绘制词云
plt.figure(figsize=(10, 8))
plt.imshow(wordcloud, interpolation="bilinear")
plt.axis("off")  # 去掉坐标轴
plt.title("相关行业词云", fontsize=20)
plt.show()
