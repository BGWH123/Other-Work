import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler, LabelEncoder
import matplotlib.pyplot as plt
import seaborn as sns

# Set the font to support Chinese characters
plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']  # For Windows
# If you're on Mac or Linux, you might use a different font like 'SimHei' or 'DejaVu Sans'
# plt.rcParams['font.sans-serif'] = ['SimHei']  # For Mac or Linux

# File path
file_path = r"D:\code\杂\Reptile\财富榜.csv"

# Load data
data = pd.read_csv(file_path, encoding="utf-8")

# Preview the data to check its structure
print(data.head())

# Function to handle fraction-like strings (e.g., '81/57')
def convert_fraction(value):
    if isinstance(value, str) and '/' in value:
        num, denom = value.split('/')  # Split numerator and denominator
        try:
            return float(num) / float(denom)  # Convert to float
        except ValueError:
            return np.nan  # Return NaN if conversion fails
    return value  # Return original value if not a fraction

# Apply the conversion function to 'Wealth' and 'Age' columns
data['财富'] = data['财富'].apply(convert_fraction)
data['年龄'] = data['年龄'].apply(convert_fraction)

# Convert any non-numeric values to NaN
data['财富'] = pd.to_numeric(data['财富'], errors='coerce')
data['年龄'] = pd.to_numeric(data['年龄'], errors='coerce')

# Fill missing values with the mean of the column
data['财富'].fillna(data['财富'].mean(), inplace=True)
data['年龄'].fillna(data['年龄'].mean(), inplace=True)

# Encode 'Industry' column with LabelEncoder
le = LabelEncoder()
data['行业编码'] = le.fit_transform(data['相关行业'])

# Preview the cleaned data
print(data[['财富', '年龄', '相关行业', '行业编码']].head())

# Standardize numerical features: 'Wealth' and 'Age'
scaler = StandardScaler()
data[['财富', '年龄']] = scaler.fit_transform(data[['财富', '年龄']])

# Prepare the features for clustering: 'Wealth', 'Age', and 'Industry Code'
X = data[['财富', '年龄', '行业编码']]

# Create and train the KMeans model (k=5)
kmeans = KMeans(n_clusters=5, random_state=42)
data['聚类标签'] = kmeans.fit_predict(X)

# Preview the clustering results
print(data[['财富', '年龄', '相关行业', '聚类标签']].head())

# Visualize the clustering results (scatter plot with color based on cluster label)
plt.figure(figsize=(10, 8))
sns.scatterplot(x='财富', y='年龄', hue='聚类标签', data=data, palette='tab10', s=100, alpha=0.6, edgecolor='w')
plt.title("K-means Clustering Results", fontsize=20)
plt.xlabel("Wealth (Standardized)", fontsize=14)
plt.ylabel("Age (Standardized)", fontsize=14)
plt.legend(title="Cluster Label", loc='upper left')
plt.show()
