from Crypto.PublicKey import RSA

#生成ca
ca_key=RSA.generate(2048)
# 保存ca私钥到文件
with open("ca_private_key.pem", "wb") as f:
    f.write(ca_key.export_key())
# 保存ca公钥到文件
with open("ca_public_key.pem", "wb") as f:
    f.write(ca_key.publickey().export_key())

