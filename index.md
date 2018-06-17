## 欢迎来到 Netkeeper.Info

这是共享校园网的办法，适用于所有pppoe拨号方式的网络（如：大名鼎鼎的netkeeper，dr.com等）。
原理为获取客户端产生的账号密码、以及心跳报文（基于现行最新tcp协议的心跳），实现路由共享网络。
仅用于学习交流，为求给在校学生谋点福利，给营运商“合理”的宽带做一点小小改变，禁止用于商业用途！！！

### 使用方法

一、改造路由固件，这里提供三种方法：

	1.直接刷入此处提供的修改版固件，修改地区对应的心跳服务器地址和端口；

	2.使用编译好的二进制和脚本DIY;
	
	3.从源码编译固件（如有必要）；

二、使用装有校园网客户端的电脑连接路由的LAN，路由的WAN连接校园网，并设置路由WAN的模式为pppoe,

	打开校园网客户端登陆，稍等几秒会提示账号密码错误（错误代码691），至此账号密码已经获取到路由，网络共享成功。

	有心跳的学校进行下一步，没有的到此即可。


三、确认网络连接成功以后，再次登陆校园网客户端，此时客户端登陆成功，保持客户端在线即可；
	此方法还不完美（登陆客户端的电脑无法访问网络，其他设备正常上网，牺牲自己成全大家^_^），欢迎大牛给出解决办法。


四、直接可用方法

	此固件基于潘多拉官方固件修改而成，路由器直接刷入即可。

	
[固件下载](https://github.com/showmec3de/showmec3de.github.io/raw/master/firmware/PandoraBox-ralink-mt7620-mt7620a-evb)
	
	将固件刷入支持OpenWrt路由器中

	本固件未做各种型号路由的指示灯和复位按钮适配，可能存在指示灯显示异常，复位按钮无法使用的情况。其他功能均可正常使用。

	刷写成功后使用WinSCP登陆后台（默认用户名root，默认密码admin，地址192.168.1.1，协议scp），

	打开/etc/rc.button文件夹内pppoe_noauth，修改两处x.x.x.x为心跳服务器的IP，修改两处xxxx为心跳服务器端口，重启路由。

[WinScp下载地址](https://winscp.net/eng/download.php)


五、需要帮助

	请在Issue提出您遇到的问题，我们将定期进行解答，感谢您的支持，如果有帮助到您，请多多将我们的页面分享给朋友、同学们。

六、声明

	本项目立旨在于分享、帮助更多的同学，能够方便的使用同学们上网。本项目不进行商业运行，不收取用户任何费用。一切都是免费的。
	不接受某运营商法务部门一切律师函。


[源码下载](https://github.com/showmec3de/showmec3de.github.io/tree/master/Source)

[固件下载](https://github.com/showmec3de/showmec3de.github.io/tree/master/firmware/)

[可执行文件和脚本](https://github.com/showmec3de/showmec3de.github.io/tree/master/Bin)
