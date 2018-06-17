这是基于源文件编译好的可执行文件，可搭配自有固件DIY使用。仅适用于mipsel平台（常见的芯片型号MT7620，如：极路由、小米路由、联想路由、优酷路由等型号），其他平台请自己动手编译。

使用方法：
1.拷贝pppd文件至路由器/usr/sbin文件夹内，替换原有pppd文件；

scp -r pppd root@192.168.1.1:/usr/sbin

2.拷贝rp-pppoe.so文件至路由器/usr/lib/pppd/xxx文件夹内，替换原有rp-pppoe.so；

scp -r rp-pppoe.so root@192.168.1.1:/usr/lib/pppd/

3.拷贝pppoe_PAP、pppoe_noauth、heartbeat三个文件至路由器/etc/rc.button文件夹内，并都赋予777权限；

scp -r pppoe_PAP root@192.168.1.1:/etc/rc.button/
scp -r pppoe_noauth root@192.168.1.1:/etc/rc.button/
scp -r heartbeat root@192.168.1.1:/etc/rc.button/
4.打开pppoe_noauth文件，修改两处x.x.x.x为心跳服务器的IP，修改两处xxxx为心跳服务器端口；

江西部分学校闪讯心跳     117.21.209.186
湖北电信心跳            58.53.196.172

5.拷贝rp-pppoe-server文件夹内pppoe-server文件至路由器/usr/sbin文件夹内，并赋予777权限；
scp -r pppoe-server root@192.168.1.1:/usr/sbin 
chmod 777 pppoe-server
6.拷贝rp-pppoe-server文件夹内rp-pppoe.so文件至路由器/etc/ppp/plugins文件夹内，并赋予777权限。

scp -r rp-pppoe.so root@192.168.1.1:/etc/ppp/plugins
chmod 777 rp-pppoe.so

拷贝文件所需的工具软件WinSCP。

注意：有两处用到同名文件rp-pppoe.so，请不要弄混。