import socket
from Crypto.PublicKey import RSA
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
import base64


# 创建UDP客户端
def udp_client():
    # 设置服务器的IP和端口
    server_ip = "127.0.0.1"
    server_port = 9999

    # 创建UDP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # 发送请求给服务器
    message = "SEND_KEYS"
    client_socket.sendto(message.encode(), (server_ip, server_port))
    print(f"向服务器发送请求: {message}")

    # 接收服务器返回的数据（公钥、私钥和数字签名）
    data, server_address = client_socket.recvfrom(4096)  # 假设数据大小不超过2048字节
    print(data)
    # 分离公钥、私钥和签名
    client_public_key_data, client_private_key_data, signature_data = data.split(b"|")

    # 解码Base64签名
    signature = base64.b64decode(signature_data)
    client_public_key = RSA.import_key(client_public_key_data)
    client_private_key = RSA.import_key(client_private_key_data)

    print("接收到客户端公钥、私钥和数字签名")

    # 加载CA公钥
    ca_public_key = load_key("ca_public_key.pem")  # CA公钥文件路径

    # 验证数字签名
    if verify_signature(ca_public_key, client_public_key_data, signature):
        print("数字签名验证通过！")
    else:
        print("数字签名验证失败！")
    # 保存自己的数字签名到文件
    save_signature(client_private_key, client_public_key_data, "my_signature.txt")
    # 关闭客户端socket
    client_socket.close()


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


# 验证数字签名
def verify_signature(ca_public_key, client_public_key_data, signature):
    """
    使用CA的公钥验证客户端公钥的数字签名
    :param ca_public_key: CA的公钥
    :param client_public_key_data: 客户端公钥文件数据
    :param signature: 客户端公钥的数字签名
    :return: 如果验证通过返回True，否则返回False
    """
    # 计算客户端公钥的SHA256哈希
    client_public_key_hash = SHA256.new(client_public_key_data)

    # 使用CA的公钥验证签名
    verifier = pkcs1_15.new(ca_public_key)
    try:
        verifier.verify(client_public_key_hash, signature)
        return True  # 签名验证成功
    except (ValueError, TypeError):
        return False  # 签名验证失败
def save_signature(private_key, data, filename):
    """
    使用客户端的私钥对数据生成数字签名，并保存到文件
    :param private_key: 客户端的私钥
    :param data: 要签名的数据
    :param filename: 保存数字签名的文件名
    """
    # 计算数据的SHA256哈希
    data_hash = SHA256.new(data)

    # 使用客户端的私钥对哈希值进行签名
    signer = pkcs1_15.new(private_key)
    signature = signer.sign(data_hash)

    # 将签名转为Base64编码格式，方便保存和传输
    signature_base64 = base64.b64encode(signature)

    # 将签名写入到文件中
    with open(filename, "wb") as sig_file:
        sig_file.write(signature_base64)

    print(f"数字签名已保存到 {filename}")

if __name__ == "__main__":
    udp_client()