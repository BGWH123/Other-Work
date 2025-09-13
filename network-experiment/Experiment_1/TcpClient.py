import socket
import time


class TcpClient:
    def __init__(self, server_ip, server_port):
        self.server_ip = server_ip
        self.server_port = server_port
        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    def connect(self):
        self.client.connect((self.server_ip, self.server_port))

    def send(self, data):
        self.client.send(data.encode())

    def receive(self):
        return self.client.recv(9999).decode()

    def close(self):
        self.client.close()

if __name__ == '__main__':
    time.sleep(1)
    tcp= TcpClient("127.0.0.1",9999)
    tcp.connect()
    tcp.send("Hello，I am client(换数据测试)")
    print(tcp.receive())
    tcp.close()