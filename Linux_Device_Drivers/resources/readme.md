# To copy Files/Directory from Rpi to Desktop(Linux PC)
scp -r DESD@192.168.221.233:/home/DESD/DD/ /home/l1-pc18/Desktop

# To copy Files/Directory from Rpi to Desktop(Linux PC)
scp -r /home/l1-pc18/Desktop/DD DESD@192.168.221.233:/home/DESD/DD/ 

# Connect SSH using WIFI
ssh DESD@192.168.221.233
Passwd: desd@123

Connect SSH using Ethernet
ssh DESD@192.168.1.100
Passwd: desd@123

Kill Process : kill -9 -1
