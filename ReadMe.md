本项目使用Dev-C++编写，GCC5.1.0编译通过，Microsoft C and C++ compilers and linker编译通过。

功能：
	分配、归还内存
	某种意义上的碎片整理（至少确保不会出现内存碎片）

注意：
	不支持数组等允许指针遍历的数据类型
	List测试.cpp为编写时辅助组件，不被包含在项目里

分工：
	苏之舟主要负责List、Pool和Main等部分
	张逸帆主要负责Block及主要的Debug等部分

原理：
	最小存储单位为Node
	List用于管理空闲Node
	Block用于使用Node
	Pool用于管理Block

	Block在建立时，要求List申请并提供Node
	存储时，寻找有空余Node的Block，将数据写入并从List中引出该Node
	删除时，将该Node清空并连接至Block尾部，插入List
	某Block使用完后，Pool会再建立新Block

参考资料：
	https://www.ibm.com/developerworks/cn/linux/l-cn-ppp/index6.html
	https://blog.csdn.net/K346K346/article/details/49538975