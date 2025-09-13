import socket
import time
class UdpClient:
    def __init__(self,host,port):
        self.host = host
        self.port = port
        self.client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    def send(self, data):
        self.client.sendto(data.encode(), (self.host, self.port))
    def receive(self):
        return self.client.recv(1024).decode()
    def close(self):
        self.client.close()
if __name__=="__main__":
    time.sleep(1)
    udp = UdpClient("127.0.0.1", 9998)
    udp.send("Hello，I am client(ucp11)")
    #print(udp.receive())
    udp.close()