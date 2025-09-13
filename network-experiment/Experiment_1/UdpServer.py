import socket
import threading

ip="127.0.0.1"
port=9998

def main():
    server_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    server_add=(ip,port)
    server_socket.bind(server_add)
    print("服务器已经启动")
    while True:
        data,client_addr=server_socket.recvfrom(1024)
        print("客户端地址：",client_addr)
        print("客户端数据：",data.decode())

if __name__=="__main__":
    main()