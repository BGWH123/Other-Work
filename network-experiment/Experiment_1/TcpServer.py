import socket
import threading

ip = "0.0.0.0"
port = 9999

def handle_client(client_socket):
    request = client_socket.recv(1024)
    print("[*] Received: %s" % request.decode())  # 解决解码问题
    client_socket.send("ACK!".encode())  # 发送数据

def main():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((ip, port))
    server.listen(5)
    print("[*] Listening on %s:%d" % (ip, port))

    while True:
        client, addr = server.accept()
        print("[*] Accepted connection from: %s:%d" % (addr[0], addr[1]))
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

if __name__ == '__main__':
    main()