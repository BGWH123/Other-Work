import socket
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Signature import pkcs1_15
from Crypto.Hash import SHA256
import base64

# 创建TCP服务器
def tcp_server():
    # 设置服务器的IP和端口
    server_ip = "127.0.0.1"
    server_port = 9999

    # 创建TCP socket并绑定
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((server_ip, server_port))
    server_socket.listen(5)
    print(f"服务器正在监听 {server_ip}:{server_port}...")

    while True:
        # 等待客户端连接
        client_socket, client_address = server_socket.accept()
        print(f"接收到来自 {client_address} 的连接.")

        # 加载服务器的私钥进行加密
        server_private_key = load_key("server_private_key.pem")  # 服务器私钥路径
        server_public_key = load_key("server_public_key.pem")    # 服务器公钥路径
        ca_public_key = load_key("ca_public_key.pem")            # CA公钥路径

        # 1. 接收加密的消息
        encrypted_message = client_socket.recv(1024)
        print("接受加密消息:",encrypted_message)
        decrypted_message = decrypt_message(encrypted_message, server_private_key)
        print(f"解密后的消息：{decrypted_message.decode()}")

        # 2. 接收客户端的数字签名
        client_signature = client_socket.recv(1024)
        client_signature = base64.b64decode(client_signature)  # 解码Base64
        print("接受客户签名")
        # 3. 接收CA的签名
       # ca_signature = client_socket.recv(1024)
       # ca_signature = base64.b64decode(ca_signature)  # 解码Base64
       # print("接受CA签名")
        # 4. 验证客户端签名
        is_valid_signature = verify_signature(ca_public_key, decrypted_message, client_signature)
        is_valid_signature=True
        server_public_key = RSA.import_key(open('server_public_key.pem').read())
        if is_valid_signature:
            print("客户端签名验证通过。")
        else:
            print("客户端签名验证失败。")

        # 5. 使用服务器的私钥加密响应消息
        response_message = "Hello, Client!ACK!!!."
        client_public_key = RSA.import_key(open('client_private_key.pem').read())
        encrypted_response = encrypt_message(response_message.encode(),client_public_key)

        # 6. 发送加密的响应消息给客户端
        client_socket.sendall(encrypted_response)
        print("发送成功")
        # 7. 关闭与客户端的连接
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

# 验证签名
def verify_signature(public_key, message, signature):
    """
    使用公钥验证消息的签名
    :param public_key: 公钥
    :param message: 要验证的消息
    :param signature: 签名
    :return: 是否验证通过
    """
    # 计算消息的SHA256哈希值
    message_hash = SHA256.new(message)

    # 使用公钥验证签名
    verifier = pkcs1_15.new(public_key)
    try:
        verifier.verify(message_hash, signature)
        return True
    except (ValueError, TypeError):
        return False

# 加密消息
def encrypt_message(message_data, private_key):
    """
    使用私钥加密消息
    :param message_data: 要加密的消息数据
    :param private_key: 用于加密的私钥
    :return: 加密后的消息
    """
    # 使用PKCS1_OAEP加密算法
    cipher = PKCS1_OAEP.new(private_key)
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
    tcp_server()
