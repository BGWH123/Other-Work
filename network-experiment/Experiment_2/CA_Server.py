import socket
from Crypto.PublicKey import RSA
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
import base64

# 创建UDP服务器
def udp_server():
    # 设置UDP服务器的IP和端口
    server_ip = "127.0.0.1"
    server_port = 9999

    # 创建UDP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind((server_ip, server_port))
    print(f"UDP服务器已启动，监听{server_ip}:{server_port}")

    # 加载CA的私钥和公钥
    ca_private_key = load_key("ca_private_key.pem")  # CA私钥文件路径
    ca_public_key = load_key("ca_public_key.pem")    # CA公钥文件路径

    while True:
        # 接收来自客户端的请求
        message, client_address = server_socket.recvfrom(1024)
        print(f"收到来自 {client_address} 的请求: {message.decode()}")

        if message.decode() == "SEND_KEYS":
            # 加载客户端的公钥和私钥
            with open("client_public_key.pem", "rb") as pub_file:
                client_public_key_data = pub_file.read()

            with open("client_private_key.pem", "rb") as pri_file:
                client_private_key_data = pri_file.read()

            print("客户端公钥和私钥已加载")

            # 对客户端公钥和私钥文件进行数字签名
            signature = sign_keys(ca_private_key, "client_public_key.pem")
            signature += sign_keys(ca_private_key, "client_private_key.pem")

            # 向客户端发送公钥、私钥和签名
            server_socket.sendto(client_public_key_data + b"|" + client_private_key_data + b"|" + signature, client_address)#发送公钥、私钥和签名
            print("已向客户端发送公钥、私钥和签名")

# 加载密钥文件
def load_key(file_path):
    """
    从文件中加载RSA公钥或私钥
    :param file_path: 密钥文件路径
    :return: 加载的RSA密钥对象
    """
    with open(file_path, "rb") as key_file:
        key_data = key_file.read()
    return RSA.import_key(key_data)

# 生成对文件的数字签名
def sign_keys(private_key, file_path):
    """
    对给定文件进行数字签名
    :param private_key: CA的私钥
    :param file_path: 要签名的文件路径
    :return: 签名数据
    """
    with open(file_path, "rb") as file:
        # 读取文件内容
        file_data = file.read()

    # 计算文件的SHA256哈希
    file_hash = SHA256.new(file_data)

    # 使用CA的私钥对哈希值进行签名
    signer = pkcs1_15.new(private_key)
    signature = signer.sign(file_hash)

    # 将签名转为Base64编码的形式
    signature_base64 = base64.b64encode(signature)

    return signature_base64

if __name__ == "__main__":
    udp_server()
