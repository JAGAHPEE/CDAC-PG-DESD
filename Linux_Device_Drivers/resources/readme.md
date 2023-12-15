## To copy Files/Directory from Rpi to Desktop(Linux PC)
scp -r DESD@192.168.221.233:/home/DESD/DD/ /home/l1-pc18/Desktop

## To copy Files/Directory from Rpi to Desktop(Linux PC)
scp -r /home/l1-pc18/Desktop/DD DESD@192.168.221.233:/home/DESD/DD/ 

## Connect SSH using WIFI
ssh DESD@192.168.221.233
Passwd: desd@123

Connect SSH using Ethernet
ssh DESD@192.168.1.100
Passwd: desd@123

Kill Process : kill -9 -1


## To Connect Raspberrypi with ETHERNET 
copy the below code to rootfs/etc/network/interfaces<br>

auto eth0\
    iface eth0 inet static\
    address 192.168.1.100\
    netmask 255.255.255.0\
    network 192.0.0.0\
<br>
<br>

## To Connect Raspberrypi with WIFI WPA2 when Raspberrypi is 
copy the below code to /etc/wpa_supplicant.conf/wpa_supplicant.conf and change the WIFI credentials SSID and Psdkey<br>

country=IN \
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\
network={ \
    ssid="<SSID>" \
    psk="<PASSWORD>" \
    key_mgmt=WPA-PSK\
    proto=RSN\
    pairwise=CCMP\
    auth_alg=OPEN\
}\
<br>
Alternate Method create wpa_supplicant.conf file and ssh file in the bootfs partition of your rpi and paste the above code int wpa_supplicant.conf and Boot.<br>
