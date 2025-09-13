from Crypto.PublicKey import RSA

# 生成2048位的RSA密钥
key = RSA.generate(2048)

# 保存私钥到文件
with open("server_private_key.pem", "wb") as f:
    f.write(key.export_key())

# 保存公钥到文件
with open("server_public_key.pem", "wb") as f:
    f.write(key.publickey().export_key())

