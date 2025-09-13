from Crypto.PublicKey import RSA

# 生成客户端的RSA密钥对
client_key = RSA.generate(2048)

# 保存客户端私钥到文件
with open("client_private_key.pem", "wb") as f:
    f.write(client_key.export_key())

# 保存客户端公钥到文件
with open("client_public_key.pem", "wb") as f:
    f.write(client_key.publickey().export_key())

