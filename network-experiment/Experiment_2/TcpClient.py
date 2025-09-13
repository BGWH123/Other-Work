import socket
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
import base64

# 创建TCP客户端
def tcp_client():
    # 设置服务器的IP和端口
    server_ip = "127.0.0.1"
    server_port = 9999

    # 创建TCP socket并连接到服务器
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((server_ip, server_port))
    print(f"已连接到服务器 {server_ip}:{server_port}.")

    # 加载客户端的私钥进行签名
    client_private_key = load_key("client_private_key.pem")  # 客户端私钥路径
    client_public_key = load_key("client_public_key.pem")    # 客户端公钥路径
    server_public_key = load_key("server_public_key.pem")    # 服务器公钥路径
    ca_public_key = load_key("ca_public_key.pem")            # CA公钥路径

    # 发送的消息
    message = "Hello from client!"

    # 1. 对消息进行签名（客户端自己签名）
    my_signature = sign_message(client_private_key, message)
    print(f"客户端生成的数字签名：{base64.b64encode(my_signature).decode()}")

    # 2. 从文件中读取CA签名（my_signature.txt）
    ca_signed_signature = load_ca_signature("my_signature.txt")

    # 3. 使用服务器的公钥加密消息
    encrypted_message = encrypt_message(message.encode(), server_public_key)

    # 将签名进行Base64编码
    encoded_my_signature = base64.b64encode(my_signature)
    encoded_ca_signature = base64.b64encode(ca_signed_signature)

    # 4. 发送加密的消息、客户端签名和CA签名到服务器
    client_socket.sendall(encrypted_message)
    client_socket.sendall(encoded_my_signature)
    client_socket.sendall(encoded_ca_signature)

    # 5. 接收服务器的加密响应消息
    encrypted_response = client_socket.recv(1024)
    #server_public_key = RSA.import_key(open('server_public_key.pem').read())
    print("接收到服务器的响应（加密）：", encrypted_response)
    decrypted_response = decrypt_message(encrypted_response, client_private_key)

    print(f"接收到服务器的响应（解密）：{decrypted_response.decode()}")

    # 6. 关闭与服务器的连接
    client_socket.close()



# 加载RSA密钥文件（公钥或私钥）
def load_key(file_path):
    """
    从文件中加载RSA公钥或私钥
    :param file_path: 密钥文件路径
    :return: 加载的RSA密钥对象
    """
    with open(file_path, "rb") as key_file:
        key_data = key_file.read()
    return RSA.import_key(key_data)

# 对消息进行签名
def sign_message(private_key, message):
    """
    使用私钥对消息进行签名
    :param private_key: 客户端私钥
    :param message: 要签名的消息
    :return: 数字签名
    """
    # 计算消息的SHA256哈希值
    message_hash = SHA256.new(message.encode())

    # 使用私钥进行签名
    signer = pkcs1_15.new(private_key)
    signature = signer.sign(message_hash)
    return signature

# 从文件中加载CA签名（my_signature.txt）
def load_ca_signature(file_path):
    """
    从文件中加载CA签名
    :param file_path: 签名文件路径
    :return: 从文件加载的签名
    """
    with open(file_path, "rb") as file:
        signature = file.read()
    return signature

# 加密消息
def encrypt_message(message_data, public_key):
    """
    使用公钥加密消息
    :param message_data: 要加密的消息数据
    :param public_key: 用于加密的公钥
    :return: 加密后的消息
    """
    # 使用PKCS1_OAEP加密算法
    cipher = PKCS1_OAEP.new(public_key)
    encrypted_message = cipher.encrypt(message_data)
    return encrypted_message

# 解密消息
def decrypt_message(encrypted_data, private_key):
    """
    使用私钥解密数据
    :param encrypted_data: 被加密的数据
    :param private_key: 解密用的私钥
    :return: 解密后的数据
    """
    # 使用PKCS1_OAEP解密算法
    cipher = PKCS1_OAEP.new(private_key)
    decrypted_data = cipher.decrypt(encrypted_data)
    return decrypted_data

if __name__ == "__main__":
    tcp_client()
